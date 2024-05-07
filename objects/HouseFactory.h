#ifndef DACHA_HOUSEFACTORY_H
#define DACHA_HOUSEFACTORY_H
#include "House.h"

class HouseFactory {
public:
  HouseFactory() = default;
  House MakeHouse(sf::Vector2f, sf::Vector2f = sf::Vector2f(80, 40), sf::Color = sf::Color(140, 140, 120));
  ~HouseFactory() = default;
};

#endif