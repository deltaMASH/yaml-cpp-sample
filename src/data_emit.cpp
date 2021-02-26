#include <yaml-cpp/yaml.h>
#include <map>
#include <fstream>

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
  map<string, CustomData> data = {
    {"key1", {"name1", 1}},
    {"key2", {"name2", 2}},
    {"key3", {"name3", 3}}
  };
  YAML::Node node;
  node = data;
  YAML::Emitter out;
  out << node;

  ofstream file("data_emit_result.yaml");
  file << out.c_str();
  file.close();
}