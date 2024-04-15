#include "../firfactory.h"

FirTree& FirFactory::FirMake(sf::Vector2f& pos) {
  sf::ConvexShape firshape;
  firshape.setPointCount(3);
  firshape.setPoint(0, sf::Vector2f(pos.x, 100) + sf::Vector2f(20, 0));
  firshape.setPoint(1, sf::Vector2f(pos.x, 100) + sf::Vector2f(0, 50));
  firshape.setPoint(2, sf::Vector2f(pos.x, 100) + sf::Vector2f(-20, 0));
  sf::ConvexShape firtrunk;
  firtrunk.setPointCount(4);
  firtrunk.setPoint(0, sf::Vector2f(pos.x, 100) + sf::Vector2f (5, 0));
  firtrunk.setPoint(1, sf::Vector2f(pos.x, 100) + sf::Vector2f (5, -5));
  firtrunk.setPoint(2, sf::Vector2f(pos.x, 100) + sf::Vector2f (-5, -5));
  firtrunk.setPoint(3, sf::Vector2f(pos.x, 100) + sf::Vector2f (-5, 0));
  FirTree tree(pos, firshape, sf::Color(0, 153, 76), firtrunk, sf::Color(107, 91, 76));
  firtrees_.push_back(&(tree));
  return *firtrees_[firtrees_.size() - 1];
}

std::vector<FirTree*> &FirFactory::GetTrees() {
  return firtrees_;
}
