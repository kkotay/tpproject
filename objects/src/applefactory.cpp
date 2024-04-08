#include "../applefactory.h"
AppleTree& AppleFactory::AppleMake(sf::Vector2f& pos) {
  Ellipse appleshape(sf::Vector2f(30, 25));
  appleshape.setPosition(sf::Vector2f(pos.x, 100) + sf::Vector2f(0, 25));
  sf::ConvexShape appletrunk;
  appletrunk.setPointCount(4);
  appletrunk.setPoint(0, sf::Vector2f(pos.x, 100) + sf::Vector2f (5, 0));
  appletrunk.setPoint(1, sf::Vector2f(pos.x, 100) + sf::Vector2f (5, -10));
  appletrunk.setPoint(2, sf::Vector2f(pos.x, 100) + sf::Vector2f (-5, -10));
  appletrunk.setPoint(3, sf::Vector2f(pos.x, 100) + sf::Vector2f (-5, 0));
  AppleTree tree (pos, appleshape, sf::Color(204, 255, 204), appletrunk, sf::Color(124, 82,35));
  appletrees_.push_back(&(tree));
  return *appletrees_[appletrees_.size() - 1];}

std::vector<AppleTree*> &AppleFactory::GetTrees() {
  return appletrees_;
}