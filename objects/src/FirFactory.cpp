#include "../FirFactory.h"

FirTree FirFactory::MakeFirTree(sf::Vector2f& position) {
  sf::ConvexShape firshape;
  firshape.setPointCount(3);
  firshape.setPoint(0, sf::Vector2f(position.x, 100) + sf::Vector2f(20, 0));
  firshape.setPoint(1, sf::Vector2f(position.x, 100) + sf::Vector2f(0, 50));
  firshape.setPoint(2, sf::Vector2f(position.x, 100) + sf::Vector2f(-20, 0));
  sf::ConvexShape firtrunk;
  firtrunk.setPointCount(4);
  firtrunk.setPoint(0, sf::Vector2f(position.x, 100) + sf::Vector2f (5, 0));
  firtrunk.setPoint(1, sf::Vector2f(position.x, 100) + sf::Vector2f (5, -20));
  firtrunk.setPoint(2, sf::Vector2f(position.x, 100) + sf::Vector2f (-5, -20));
  firtrunk.setPoint(3, sf::Vector2f(position.x, 100) + sf::Vector2f (-5, 0));
  FirTree tree(position, firshape, sf::Color(0, 153, 76), firtrunk, sf::Color(107, 91, 76));
  return tree;
}