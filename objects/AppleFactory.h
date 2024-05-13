#ifndef DACHA_APPLEFACTORY_H
#define DACHA_APPLEFACTORY_H
#include "AppleTree.h"

class AppleFactory {
public:
  AppleFactory() = default;
  AppleTree MakeAppleTree(sf::Vector2f&);
  ~AppleFactory() = default;
};

#endif
