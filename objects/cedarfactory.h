#ifndef DACHA_CEDARFACTORY_H
#define DACHA_CEDARFACTORY_H
#include "cedartree.h"

class CedarFactory {
  std::vector<CedarTree> cedartrees_;

public:
  CedarFactory() = default;
  CedarTree& CedarMake(sf::Vector2f& pos);
  std::vector<CedarTree>& GetTrees();
  ~CedarFactory() {
    cedartrees_.clear();
  }
};
#endif
