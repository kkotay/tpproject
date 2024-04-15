#ifndef MYDESMOS_TREE_H
#define MYDESMOS_TREE_H
#include "object.h"
#include <SFML/Graphics.hpp>


class Tree : public Object {
 protected:
  sf::ConvexShape crown_{};
  sf::ConvexShape trunk_{};
  sf::CircleShape topview_{};

 public:
  Tree() = default;
  void SetCrownColor(sf::Color);
  void SetBorderCrownColor(sf::Color);
  void SetTrunkColor(sf::Color);
  void SetBorderTrunkColor(sf::Color);
  Tree(sf::Vector2f, const sf::ConvexShape&, sf::Color, const sf::ConvexShape&, sf::Color, float);
  void draw(sf::RenderTexture&) const override;
  void drawtop(sf::RenderTexture&) const override;
  void SearchShadow(float) override;
  ~Tree() = default;
};


#endif
