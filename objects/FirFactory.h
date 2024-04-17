#ifndef DACHA_FIRFACTORY_H
#define DACHA_FIRFACTORY_H
#include "FirTree.h"

class FirFactory {
public:
  FirFactory() = default;
  FirTree MakeFirTree(sf::Vector2f&);
  ~FirFactory() = default;
};

#endif
