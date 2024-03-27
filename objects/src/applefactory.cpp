#include "../applefactory.h"
AppleTree& AppleFactory::AppleMake(sf::Vector2f& pos) {
  Ellipse appleshape(sf::Vector2f(30, 25));
  sf::ConvexShape appletrunk;
  appletrunk.setPointCount(4);
  appletrunk.setPoint(0, pos + sf::Vector2f (5, 0));
  appletrunk.setPoint(0, pos + sf::Vector2f (5, -10));
  appletrunk.setPoint(0, pos + sf::Vector2f (-5, -10));
  appletrunk.setPoint(0, pos + sf::Vector2f (-5, 0));
  appletrees_.push_back(AppleTree{pos, appleshape, sf::Color(204, 255, 204), appletrunk, sf::Color(124, 82,35)});
  return appletrees_[appletrees_.size() - 1];}

std::vector<AppleTree> &AppleFactory::GetTrees() {
  return appletrees_;
}

};