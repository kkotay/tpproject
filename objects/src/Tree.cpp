#include "../Tree.h"

#include <iostream>

Tree::Tree(const sf::Vector2f position, const sf::ConvexShape& crown, const sf::Color crowncolor, const sf::ConvexShape& trunk, const sf::Color trunkcolor, float rad) {
  position_ = position;
  crown_ = crown;
  crown_.setPosition(position_);
  crown_.setFillColor(crowncolor);
  trunk_ = trunk;
  trunk_.setPosition(position_);
  trunk_.setFillColor(trunkcolor);
  topview_ = sf::CircleShape(rad);
  topview_.setFillColor(crowncolor);
}

void Tree::setCrownColor(sf::Color color) {
  crown_.setFillColor(color);
  crown_.setOutlineColor(color - sf::Color(0, 30, 0));
  topview_.setFillColor(color);
  topview_.setOutlineColor(color - sf::Color(0, 30, 0));
}

void Tree::setBorderCrownColor(sf::Color color) {
  crown_.setOutlineColor(color);
  topview_.setOutlineColor(color);
}

void Tree::setTrunkColor(sf::Color color) {
  trunk_.setFillColor(color);
}


void Tree::setBorderTrunkColor(sf::Color color) {
  crown_.setOutlineColor(color);
}

void Tree::draw(sf::RenderTexture& window) const {
  window.draw(trunk_);
  window.draw(crown_);
}

void Tree::drawTop(sf::RenderTexture& window) const {
  window.draw(topview_);
}

void Tree::SearchShadow(float tg) {
  if (tg == 0) {
    tg += 0.01;
  }
  for (size_t i = 0; i < trunk_.getPointCount(); ++i) {
    shadow_.setPoint(i, position_ + sf::Vector2f(trunk_.getPoint(i).x, trunk_.getPoint(i).y / tg));
  }
  for (size_t i = trunk_.getPointCount(); i < crown_.getPointCount() + trunk_.getPointCount(); ++i) {
    shadow_.setPoint(i, position_ + sf::Vector2f(crown_.getPoint(i).x, crown_.getPoint(i).y / tg));
  }
}