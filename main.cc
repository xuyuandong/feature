#include "feature_manager.h"
#include "feature_context.h"
#include "feature_register.h"
#include "data_struct.h"
#include <iostream>


using namespace std;

int main(int argc, char* argv[]) {
  RecommendLog log;
  log.uid = 5;
  log.docid = 8;
  const char* tags[3] = {"a","b","c"};
  for (int i = 0; i < 3; ++i)
      log.doc_tags.emplace_back(tags[i]);

  vector<uint16_t> groups;
  for (uint16_t i = 0; i < 1000; ++i)
      groups.emplace_back(i);
  FeatureContext fc;
  fc.Parse(log);

  FeatureManager fm;
  FeatureRegister<FeatureManager, FeatureContext>::Get().Run(groups, &fm, &fc);

  auto fv = fm.Get();
  for (auto kv : fv)
      cout << kv.first << " " << kv.second << endl;

  return 0;
}
