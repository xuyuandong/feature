#ifndef FEATURE_CONTEXT_H_
#define FEATURE_CONTEXT_H_

#include "data_struct.h"

class FeatureContext {
 public:
  // offline
  void Parse(const RecommendLog& log);
  // online
  void Parse(const UserProfile& up);
  void Parse(const RecContext& rc);
  void Parse(const OnlineDoc& doc);
  // 
  const Sample& data() { return sample_; }

 private:  
  const RecommendLog* offline_ = nullptr;
  const OnlineDoc* online_ = nullptr;
  
  Sample sample_;

};


#endif
