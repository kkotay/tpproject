#include "../AppleTree.h"

AppleTree::AppleTree(sf::Vector2f pon, const Ellipse& crown, sf::Color crowncolor, const sf::ConvexShape& trunk, sf::Color trunkcolor) {
  position_ = pon;
  crown_.setPointCount(crown.getPointCount());
  for (int i = 0; i < crown.getPointCount(); ++i) {
    crown_.setPoint(i, crown.getPoint(i) + sf::Vector2f(position_.x, 100) - sf::Vector2f(crown.getRadius().x, 0));
  }
  crown_.setFillColor(crowncolor);
  crown_.setOutlineColor(sf::Color(crowncolor.r, crowncolor.g - 30, crowncolor.b));
  crown_.setOutlineThickness(3);
  trunk_ = trunk;
  trunk_.setFillColor(trunkcolor);
  trunk_.setOutlineThickness(2);
  trunk_.setOutlineColor(sf::Color(trunkcolor.r - 20, trunkcolor.g - 20, trunkcolor.b - 20));
  topview_ = sf::CircleShape(crown.getRadius().x);
  topview_.setFillColor(crowncolor);
  topview_.setOutlineColor(sf::Color(crowncolor.r, crowncolor.g - 30, crowncolor.b));
  topview_.setOutlineThickness(3);
  topview_.setPosition(position_ - sf::Vector2f(crown.getRadius().x, crown.getRadius().x));
}