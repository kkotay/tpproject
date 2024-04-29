#include "../CedarTree.h"


CedarTree::CedarTree(sf::Vector2f pon, const sf::ConvexShape& crown, sf::Color crowncolor, const sf::ConvexShape& trunk, sf::Color trunkcolor) {
  position_ = pon;
  crown_ = crown;
  crown_.setFillColor(crowncolor);
  crown_.setOutlineColor(crowncolor - sf::Color(0, 30, 0));
  crown_.setOutlineThickness(6);
  trunk_ = trunk;
  trunk_.setFillColor(trunkcolor);
  trunk_.setOutlineThickness(2);
  trunk_.setOutlineColor(trunkcolor - sf::Color(20, 20, 20));
  topview_ = sf::CircleShape(20);
  topview_.setFillColor(crowncolor);
  topview_.setOutlineColor(crowncolor - sf::Color(0, 30, 0));
}