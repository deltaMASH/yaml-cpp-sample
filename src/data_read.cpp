#include <yaml-cpp/yaml.h>
#include <map>
#include <iostream>

using namespace std;

struct CustomData
{
  string name;
  int value;
};

namespace YAML
{
  template<>
  struct convert<CustomData>
  {
    static Node encode(const CustomData& rhs) {
      Node node;
      node["name"] = rhs.name;
      node["value"] = rhs.value;
      return node;
    }

    static bool decode(const Node& node, CustomData& rhs) {
      rhs.name = node["name"].as<string>();
      rhs.value = node["value"].as<int>();
      return true;
    }
  };
}

int main(int argc, char** argv)
{
  YAML::Node node = YAML::LoadFile(argv[1]);
  auto data = node.as<map<string, CustomData>>();
  for (auto kv : data) {
    cout << "key: " << kv.first << endl;
    cout << "  name: " << kv.second.name << endl;
    cout << "  value: " << kv.second.value << endl;
    cout << endl;
  }

  return 0;
}
