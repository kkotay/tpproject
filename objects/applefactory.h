#ifndef DACHA_APPLEFACTORY_H
#define DACHA_APPLEFACTORY_H
#include "appletree.h"

class AppleFactory {
  std::vector<AppleTree*> appletrees_;

public:
  AppleFactory() = default;
  AppleTree& AppleMake(sf::Vector2f& pos);
  std::vector<AppleTree*>& GetTrees();
  ~AppleFactory() {
    appletrees_.clear();
  }
};

#endif //DACHA_APPLEFACTORY_H
