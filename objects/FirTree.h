#ifndef DACHA_FIRTREE_H
#define DACHA_FIRTREE_H
#include "Tree.h"

class FirTree : public Tree {
 public:
  FirTree() = default;
  FirTree(sf::Vector2f, const sf::ConvexShape&, sf::Color, const sf::ConvexShape&, sf::Color, float);
  ~FirTree() = default;
};

#endif