#include "../firfactory.h"

FirTree& FirFactory::FirMake(sf::Vector2f& pos) {
  sf::ConvexShape firshape;
  firshape.setPointCount(3);
  firshape.setPoint(0, pos + sf::Vector2f(20, 0));
  firshape.setPoint(1, pos + sf::Vector2f(0, 50));
  firshape.setPoint(2, pos + sf::Vector2f(-20, 0));
  sf::ConvexShape firtrunk;
  firtrunk.setPointCount(4);
  firtrunk.setPoint(0, pos + sf::Vector2f (5, 0));
  firtrunk.setPoint(0, pos + sf::Vector2f (5, -5));
  firtrunk.setPoint(0, pos + sf::Vector2f (-5, -5));
  firtrunk.setPoint(0, pos + sf::Vector2f (-5, 0));
  firtrees_.push_back(FirTree{pos, firshape, sf::Color(0, 153, 76), firtrunk, sf::Color(107, 91, 76)});
  return firtrees_[firtrees_.size() - 1];
}

std::vector<FirTree> &FirFactory::GetTrees() {
  return firtrees_;
}
