#ifndef DACHA_FIRFACTORY_H
#define DACHA_FIRFACTORY_H
#include "firtree.h"
class FirFactory {
  std::vector<FirTree> firtrees_;

public:
  FirFactory() = default;
  FirTree& FirMake(sf::Vector2f& pos);
  std::vector<FirTree>& GetTrees();
  ~FirFactory() {
    firtrees_.clear();
  }
};
#endif //DACHA_FIRFACTORY_H
