#ifndef DACHA_CEDARFACTORY_H
#define DACHA_CEDARFACTORY_H
#include "CedarTree.h"

class CedarFactory {
public:
  CedarFactory() = default;
  CedarTree MakeCedarTree(sf::Vector2f&);
  ~CedarFactory() = default;
};

#endif
