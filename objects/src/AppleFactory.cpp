#include "../AppleFactory.h"
AppleTree AppleFactory::MakeAppleTree(sf::Vector2f& position) {
  Ellipse appleshape(sf::Vector2f(30, 25));
  appleshape.setPosition(sf::Vector2f(position.x, 100) + sf::Vector2f(0, 25));
  sf::ConvexShape appletrunk;
  appletrunk.setPointCount(4);
  appletrunk.setPoint(0, sf::Vector2f(position.x, 100) + sf::Vector2f (5, 0));
  appletrunk.setPoint(1, sf::Vector2f(position.x, 100) + sf::Vector2f (5, -20));
  appletrunk.setPoint(2, sf::Vector2f(position.x, 100) + sf::Vector2f (-5, -20));
  appletrunk.setPoint(3, sf::Vector2f(position.x, 100) + sf::Vector2f (-5, 0));
  AppleTree tree (position, appleshape, sf::Color(204, 255, 204), appletrunk, sf::Color(124, 82, 35));
  return tree;
}