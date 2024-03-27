#include "../cedarfactory.h"
CedarTree& CedarFactory::CedarMake(sf::Vector2f& pos) {
  sf::ConvexShape cedarshape;
  cedarshape.setPointCount(6);
  cedarshape.setPoint(0, pos + sf::Vector2f(30, 0));
  cedarshape.setPoint(1, pos + sf::Vector2f(40, 10));
  cedarshape.setPoint(2, pos + sf::Vector2f(35, 30));
  cedarshape.setPoint(3, pos + sf::Vector2f(-35, 30));
  cedarshape.setPoint(4, pos + sf::Vector2f(-40, 10));
  cedarshape.setPoint(5, pos + sf::Vector2f(-30, 0));
  sf::ConvexShape cedartrunk;
  cedartrunk.setPointCount(4);
  cedartrunk.setPoint(0, pos + sf::Vector2f (5, 0));
  cedartrunk.setPoint(0, pos + sf::Vector2f (5, -20));
  cedartrunk.setPoint(0, pos + sf::Vector2f (-5, -20));
  cedartrunk.setPoint(0, pos + sf::Vector2f (-5, 0));
  cedartrees_.push_back(CedarTree{pos, cedarshape, sf::Color(0, 153, 0), cedartrunk, sf::Color(146, 133, 105)});
  return cedartrees_[cedartrees_.size() - 1];
}

std::vector<CedarTree> &CedarFactory::GetTrees() {
  return cedartrees_;
}
