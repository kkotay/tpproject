#include "BushFactory.h"

Bush BushFactory::MakeBush(sf::Vector2f position) {
  sf::ConvexShape shape;
  shape.setPointCount(5);
  shape.setPoint(0, sf::Vector2f(position.x, 85) + sf::Vector2f (-15, 0));
  shape.setPoint(1, sf::Vector2f(position.x, 85) + sf::Vector2f (-20, 17));
  shape.setPoint(2, sf::Vector2f(position.x, 85) + sf::Vector2f (0, 30));
  shape.setPoint(3, sf::Vector2f(position.x, 85) + sf::Vector2f (20, 17));
  shape.setPoint(4, sf::Vector2f(position.x, 85) + sf::Vector2f (15, 0));
  Bush bush(position, shape, sf::Color(0, 51, 51), 20);
  return bush;
}
