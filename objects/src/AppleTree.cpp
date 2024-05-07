#include "../AppleTree.h"

AppleTree::AppleTree(sf::Vector2f pon, const Ellipse& crown, sf::Color crowncolor, const sf::ConvexShape& trunk, sf::Color trunkcolor) {
  position_ = pon;
  crown_.setPointCount(crown.getPointCount());
  for (int i = 0; i < crown.getPointCount(); ++i) {
    crown_.setPoint(i, crown.getPoint(i) + sf::Vector2f(position_.x, 100) - sf::Vector2f(crown.getRadius().x, 0));
  }
  crown_.setFillColor(crowncolor);
  crown_.setOutlineColor(crowncolor - sf::Color(0, 30, 0));
  crown_.setOutlineThickness(6);
  trunk_ = trunk;
  trunk_.setFillColor(trunkcolor);
  trunk_.setOutlineThickness(2);
  trunk_.setOutlineColor(trunkcolor - sf::Color(20, 20, 20));
  topview_ = sf::CircleShape(crown.getRadius().x);
  topview_.setFillColor(crowncolor);
  topview_.setOutlineColor(crowncolor - sf::Color(0, 30, 0));
  topview_.setPosition(position_ - sf::Vector2f(crown.getRadius().x, crown.getRadius().x));
}