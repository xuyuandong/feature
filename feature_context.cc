#include "feature_manager.h"
#include "feature_register.h"
#include "feature_context.h"

void FeatureContext::Parse(const RecommendLog& log) {
  offline_ = &log;
  sample_.user_id_ = log.uid;
  sample_.item_id_ = log.docid;
  sample_.item_tags_ = log.doc_tags;
}

void FeatureContext::Parse(const UserProfile& up) {
  sample_.user_id_ = up.uid;
}

void FeatureContext::Parse(const RecContext& rc) {

}

void FeatureContext::Parse(const OnlineDoc& doc) {
  online_ = &doc;
  sample_.item_id_ = doc.id;
  sample_.item_tags_ = doc.tags;
}

using Manager = FeatureManager;
using Context = FeatureContext;

#define REGISTER_FEATURE(g)                                  \
    static void Callback##g(uint16_t, Manager*, Context*);   \
    static FeatureRegister<Manager, Context>::Helper register_callback_##g(    \
	    (uint16_t)g, #g, &Callback##g);                    \
    void Callback##g(uint16_t group, Manager* m, Context* c) \


REGISTER_FEATURE(kUserId) {
  m->AddFeature(group, c->data().user_id_);
}

REGISTER_FEATURE(kItemId) {
  m->AddFeature(group, c->data().item_id_);
}

REGISTER_FEATURE(kItemTags) {
  int size = std::min(10, (int)c->data().item_tags_.size());
  for (int i = 0; i < size; ++i) {
    // other logic to process each tag
    m->AddFeature(group, c->data().item_tags_[i]);
  }
}

