#ifndef DACHA_HOUSEFACTORY_H
#define DACHA_HOUSEFACTORY_H
#include "House.h"

class HouseFactory {
public:
  HouseFactory() = default;
  House MakeHouse(sf::Vector2f, sf::Vector2f = sf::Vector2f(120, 60), sf::Color = sf::Color(100, 100, 100));
  ~HouseFactory() = default;
};

#endif