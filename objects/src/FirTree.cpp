#include "../FirTree.h"

FirTree::FirTree(sf::Vector2f pon, const sf::ConvexShape& crown, sf::Color crowncolor, const sf::ConvexShape& trunk, sf::Color trunkcolor, float radius) {
  position_ = pon;
  crown_ = crown;
  crown_.setFillColor(crowncolor);
  crown_.setOutlineColor(sf::Color(crowncolor.r, crowncolor.g - 30, crowncolor.b));
  crown_.setOutlineThickness(3);
  trunk_ = trunk;
  trunk_.setFillColor(trunkcolor);
  trunk_.setOutlineThickness(2);
  trunk_.setOutlineColor(sf::Color(trunkcolor.r - 20, trunkcolor.g - 20, trunkcolor.b - 20));
  topview_ = sf::CircleShape(radius);
  topview_.setFillColor(crowncolor);
  topview_.setOutlineColor(sf::Color(crowncolor.r, crowncolor.g - 30, crowncolor.b));
  topview_.setOutlineThickness(3);
  topview_.setPosition(position_ - sf::Vector2f(radius, radius));
}