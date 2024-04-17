#include "../HouseFactory.h"

House HouseFactory::MakeHouse(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
  House house = House(position, size, color);
  return house;
}