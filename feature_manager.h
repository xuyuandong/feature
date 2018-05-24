#ifndef FEATURE_MANAGER_H_
#define FEATURE_MANAGER_H_

#include <map>
#include <vector>
#include <string>

using Key = uint64_t;
using Val = float;

#define GROUP_SHIFT 48
class HashFunction {
 public:
  static Key Hash(uint64_t g, uint64_t f) {
    return (g << GROUP_SHIFT) + ((f *9973)& 0x0000ffff);
  }
  static Key Hash(uint64_t g, const char* p, size_t len) {
    return (g << GROUP_SHIFT) + ((p[0] *9973)& 0x0000ffff);
  }
};

class FeatureManager {
 public:
  const std::vector<std::pair<Key,Val>> Get() const {
      return features_;
  }

  void AddFeature(uint16_t group, uint64_t f, Val weight = 1) {
    features_.emplace_back(HashFunction::Hash(group, f), weight);
  }
  void AddFeature(uint16_t group, const std::string& f, Val weight = 1) {
    features_.emplace_back(HashFunction::Hash(group, f.c_str(), f.size()), weight);
  }
  void AddCrossFeature(uint16_t group, uint64_t f1, const std::string& f2, Val weight = 1) {
    //TODO
  }

 private:
  std::vector<std::pair<Key,Val>> features_;

};

#endif
