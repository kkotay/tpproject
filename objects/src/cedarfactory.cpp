#include "../cedarfactory.h"
CedarTree& CedarFactory::CedarMake(sf::Vector2f& pos) {
  sf::ConvexShape cedarshape;
  cedarshape.setPointCount(6);
  cedarshape.setPoint(0, sf::Vector2f(pos.x, 100) + sf::Vector2f(30, 0));
  cedarshape.setPoint(1, sf::Vector2f(pos.x, 100) + sf::Vector2f(40, 10));
  cedarshape.setPoint(2, sf::Vector2f(pos.x, 100) + sf::Vector2f(35, 30));
  cedarshape.setPoint(3, sf::Vector2f(pos.x, 100) + sf::Vector2f(-35, 30));
  cedarshape.setPoint(4, sf::Vector2f(pos.x, 100) + sf::Vector2f(-40, 10));
  cedarshape.setPoint(5, sf::Vector2f(pos.x, 100) + sf::Vector2f(-30, 0));
  sf::ConvexShape cedartrunk;
  cedartrunk.setPointCount(4);
  cedartrunk.setPoint(0, sf::Vector2f(pos.x, 100) + sf::Vector2f (5, 0));
  cedartrunk.setPoint(1, sf::Vector2f(pos.x, 100) + sf::Vector2f (5, -20));
  cedartrunk.setPoint(2, sf::Vector2f(pos.x, 100) + sf::Vector2f (-5, -20));
  cedartrunk.setPoint(3, sf::Vector2f(pos.x, 100) + sf::Vector2f (-5, 0));
  CedarTree tree(pos, cedarshape, sf::Color(0, 153, 0), cedartrunk, sf::Color(146, 133, 105));
  cedartrees_.push_back(&(tree));
  return *cedartrees_[cedartrees_.size() - 1];
}

std::vector<CedarTree*> &CedarFactory::GetTrees() {
  return cedartrees_;
}
