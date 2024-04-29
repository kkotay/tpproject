#ifndef DACHA_CEDARTREE_H
#define DACHA_CEDARTREE_H
#include "Tree.h"

class CedarTree : public Tree {
 public:
  CedarTree() = default;
  CedarTree(sf::Vector2f, const sf::ConvexShape&, sf::Color, const sf::ConvexShape&, sf::Color);
  ~CedarTree() = default;
};

#endif