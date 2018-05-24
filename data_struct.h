#ifndef DATA_STRUCT_H_
#define DATA_STRUCT_H_

#include <string>
#include <vector>

// fake structure for demo
struct RecommendLog {
  uint64_t uid;
  uint64_t docid;
  std::vector<std::string> doc_tags; 
};
struct UserProfile {
  uint64_t uid;
};
struct RecContext {
};
struct OnlineDoc {
  uint64_t id;
  std::vector<std::string> tags;
};


// feature definitions
enum FeatureGroup {
  kUserId = 0,
  //
  kItemId = 100,
  kItemTags = 101,
  //
  kFeatureGroupEnd
};

struct Sample {
  uint64_t user_id_;
  uint64_t item_id_;
  std::vector<std::string> item_tags_;
};


#endif
