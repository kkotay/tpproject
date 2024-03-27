#include "../tree.h"

#include <utility>

Tree::Tree(const sf::Vector2f pon, const sf::ConvexShape& crown, const sf::Color crowncolor, const sf::ConvexShape& trunk, const sf::Color trunkcolor) {
  pos_ = pon;
  crown_ = crown;
  crown_.setPosition(pos_);
  crown_.setFillColor(crowncolor);
  trunk_ = trunk;
  trunk_.setPosition(pos_);
  trunk_.setFillColor(trunkcolor);
}

void Tree::SetCrownColor(sf::Color color) {
  crown_.setFillColor(color);
}

void Tree::SetBorderCrownColor(sf::Color color) {
  crown_.setOutlineColor(color);
}

void Tree::SetTrunkColor(sf::Color color) {
  trunk_.setFillColor(color);
}


void Tree::SetBorderTrunkColor(sf::Color color) {
  crown_.setOutlineColor(color);
}

void Tree::draw(sf::RenderWindow& window) const {
  window.draw(trunk_);
  window.draw(crown_);
}

void Tree::SearchShadow(unsigned int) const {
// coming soon
}


