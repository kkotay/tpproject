#ifndef DACHA_TREE_H
#define DACHA_TREE_H
#include "Object.h"
#include <SFML/Graphics.hpp>


class Tree : public Object {
 protected:
  sf::ConvexShape crown_{};
  sf::ConvexShape trunk_{};
  sf::CircleShape topview_{};

 public:
  Tree() = default;
  void setCrownColor(sf::Color);
  void setBorderCrownColor(sf::Color);
  void setTrunkColor(sf::Color);
  void setBorderTrunkColor(sf::Color);
  Tree(sf::Vector2f, const sf::ConvexShape&, sf::Color, const sf::ConvexShape&, sf::Color, float);
  void draw(sf::RenderTexture&) const override;
  void drawTop(sf::RenderTexture&) const override;
  sf::ConvexShape getHardShadow(float) override;
  void SearchShadow(float) override;
  ~Tree() = default;
};

#endif