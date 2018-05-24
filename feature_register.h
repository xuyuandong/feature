#ifndef FEATURE_REGISTER_H_
#define FEATURE_REGISTER_H_

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

template<class Manager, class Context>
class FeatureRegister {
 public:
  using Callback = void (*)(uint16_t, Manager*, Context*);

  void Register(uint16_t group, const std::string& name, Callback cb) {
    group2name_[group] = name;
    group2cb_[group] = callbacks_.size();
    callbacks_.push_back(cb);
  }

  void Run(const std::vector<uint16_t>& groups, Manager* manager, Context* context) {
    for (auto g : groups) {
      auto iter = group2cb_.find(g);
      if (iter != group2cb_.end()) {
        callbacks_[iter->second](g, manager, context);
      }
    }
  }

  static FeatureRegister& Get() {
    static FeatureRegister instance_;
    return instance_;
  }

  class Helper {
   public:
    Helper(uint16_t group, const std::string& name, Callback cb) {
      FeatureRegister::Get().Register(group, name, cb);
    }  
  };

 private:

  std::vector<Callback> callbacks_;
  std::unordered_map<uint16_t, int> group2cb_;
  std::unordered_map<uint16_t, std::string> group2name_;
};

#endif
