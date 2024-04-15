#ifndef DACHA_HOUSEFACTORY_H
#define DACHA_HOUSEFACTORY_H
#include "house.h"

class HouseFactory {
 protected:
  std::vector<Object*> houses_;

public:
  HouseFactory() = default;
  void HouseMake(sf::Vector2f, sf::Vector2f = sf::Vector2f(120, 60), sf::Color = sf::Color(100, 100, 100));
  std::vector<Object*>& GetHouses();
  ~HouseFactory() {
    houses_.clear();
  }
};


#endif
