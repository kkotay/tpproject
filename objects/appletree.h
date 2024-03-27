#ifndef DACHA_APPLETREE_H
#define DACHA_APPLETREE_H
#include "tree.h"

class AppleTree : public Tree {
  public:
    AppleTree() = default;
    AppleTree(sf::Vector2f, const Ellipse&, sf::Color, const sf::ConvexShape&, sf::Color);
    ~AppleTree() = default;
};
#endif