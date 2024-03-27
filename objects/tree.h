#ifndef MYDESMOS_TREE_H
#define MYDESMOS_TREE_H
#include "object.h"
#include <SFML/Graphics.hpp>


class Tree : protected Object {
 protected:
  sf::ConvexShape crown_{};
  sf::ConvexShape trunk_{};
  sf::ConvexShape crownshadow_{};
  sf::ConvexShape trunkshadow_{};
  void SearchShadow(unsigned int) const override;

 public:
  Tree() = default;
  void SetCrownColor(sf::Color);
  void SetBorderCrownColor(sf::Color);
  void SetTrunkColor(sf::Color);
  void SetBorderTrunkColor(sf::Color);
  Tree(sf::Vector2f, const sf::ConvexShape&, sf::Color, const sf::ConvexShape&, sf::Color);
  void draw(sf::RenderWindow&) const override;
  ~Tree() = default;
};


#endif
