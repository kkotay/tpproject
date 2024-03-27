#include "../housefactory.h"

House& HouseFactory::HouseMake(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
  houses_.push_back(House{pos, size, color});
  return houses_[houses_.size() - 1];
}

std::vector<House>& HouseFactory::GetHouses() {
  return houses_;
}
