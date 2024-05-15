#include "../Tree.h"
#include "iostream"

Tree::Tree(const sf::Vector2f position, const sf::ConvexShape& crown, const sf::Color crowncolor, const sf::ConvexShape& trunk, const sf::Color trunkcolor, float radius) {
  position_ = position;
  crown_ = crown;
  crown_.setPosition(position_);
  crown_.setFillColor(crowncolor);
  trunk_ = trunk;
  trunk_.setPosition(position_);
  trunk_.setFillColor(trunkcolor);
  topview_ = sf::CircleShape(radius);
  topview_.setFillColor(crowncolor);
  topview_.setPosition(position_);
  topview_.setOutlineThickness(2);
  topview_.setOutlineColor(crowncolor - sf::Color(0, 30, 0));
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
    shadow_.setPointCount(4);
    for (size_t i = 0; i < trunk_.getPointCount(); ++i) {
      if (trunk_.getPoint(i).y == 80) {
        shadow_.setPoint(i, (sf::Vector2f(trunk_.getPoint(i).x, position_.y)));
      } else {
        shadow_.setPoint(i, (sf::Vector2f(trunk_.getPoint(i).x, 640)));
      }
    }
    return;
  }
  int count = 32;
  shadow_.setPointCount(trunk_.getPointCount() + crown_.getPointCount() * count);
  for (size_t i = 0; i < trunk_.getPointCount(); ++i) {
    shadow_.setPoint(i, (sf::Vector2f(trunk_.getPoint(i).x, position_.y + (trunk_.getPoint(i).y - 80) / tg)));
  }
  sf::CircleShape circle;
  circle.setPointCount(count);
  circle.setPosition(position_);
  for (size_t i = 0; i < crown_.getPointCount(); ++i) {
    float radius = std::fabs(crown_.getPoint(i).x - position_.x);
    circle.setRadius(std::fabs(radius));
    for (size_t j = 0; j < count; ++j) {
      shadow_.setPoint(trunk_.getPointCount() + i * count + j,
                       (sf::Vector2f(circle.getPoint(j).x + position_.x - radius,
                           position_.y + circle.getPoint(j).y - radius + (crown_.getPoint(i).y - 80) / tg)));
    }
  }
}

sf::ConvexShape Tree::getHardShadow(float tg) {
  sf::ConvexShape shadow;
  if (tg == 0) {
    shadow.setPointCount(4);
    for (size_t i = 0; i < trunk_.getPointCount(); ++i) {
      if (trunk_.getPoint(i).y == 80) {
        shadow.setPoint(i, (sf::Vector2f(trunk_.getPoint(i).x, position_.y)));
      } else {
        shadow.setPoint(i, (sf::Vector2f(trunk_.getPoint(i).x, 640)));
      }
    }
    return shadow;
  }
  shadow.setPointCount(trunk_.getPointCount() + crown_.getPointCount());
  for (size_t i = 0; i < trunk_.getPointCount(); ++i) {
    shadow.setPoint(i, (sf::Vector2f(trunk_.getPoint(i).x, position_.y + (trunk_.getPoint(i).y - 80) / tg)));
  }
  for (size_t i = 0; i < crown_.getPointCount(); ++i) {
    shadow.setPoint(i + trunk_.getPointCount(), (sf::Vector2f(crown_.getPoint(i).x, position_.y + (crown_.getPoint(i).y - 80) / tg)));
  }
  return shadow;
}
