#include "../CedarFactory.h"
CedarTree CedarFactory::MakeCedarTree(sf::Vector2f& position) {
  float k = 2;
  sf::ConvexShape cedarshape;
  cedarshape.setPointCount(7);
  cedarshape.setPoint(0, sf::Vector2f(position.x, 100) + sf::Vector2f(30 * k, 0));
  cedarshape.setPoint(1, sf::Vector2f(position.x, 100) + sf::Vector2f(40 * k, 10));
  cedarshape.setPoint(2, sf::Vector2f(position.x, 100) + sf::Vector2f(30 * k, 90));
  cedarshape.setPoint(3, sf::Vector2f(position.x, 100) + sf::Vector2f(0, 100));
  cedarshape.setPoint(4, sf::Vector2f(position.x, 100) + sf::Vector2f(-30 * k, 90));
  cedarshape.setPoint(5, sf::Vector2f(position.x, 100) + sf::Vector2f(-40 * k, 10));
  cedarshape.setPoint(6, sf::Vector2f(position.x, 100) + sf::Vector2f(-30 * k, 0));
  sf::ConvexShape cedartrunk;
  cedartrunk.setPointCount(4);
  cedartrunk.setPoint(0, sf::Vector2f(position.x, 100) + sf::Vector2f (5 * k, 0));
  cedartrunk.setPoint(1, sf::Vector2f(position.x, 100) + sf::Vector2f (5 * k, -20));
  cedartrunk.setPoint(2, sf::Vector2f(position.x, 100) + sf::Vector2f (-5 * k, -20));
  cedartrunk.setPoint(3, sf::Vector2f(position.x, 100) + sf::Vector2f (-5 * k, 0));
  CedarTree tree(position, cedarshape, sf::Color(0, 93, 0), cedartrunk, sf::Color(146, 133, 105), 40 * k);
  return tree;
}