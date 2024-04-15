#include "../housefactory.h"

void HouseFactory::HouseMake(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
  House hou(pos, size, color);
  houses_.push_back(&(hou));
}

std::vector<Object*>& HouseFactory::GetHouses() {
  return houses_;
}
