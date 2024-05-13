#ifndef DACHA_BUSHFACTORY_H
#define DACHA_BUSHFACTORY_H
#include "Bush.h"

class BushFactory {
public:
  BushFactory() = default;
  Bush MakeBush(sf::Vector2f);
  ~BushFactory() = default;
};

#endif
