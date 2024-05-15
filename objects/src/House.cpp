#include "../House.h"

House::House(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
  position_ = pos;
  size_ = size;
  color_ = color;
  roof_.setPointCount(4);
  roof_.setPoint(0, sf::Vector2f(position_ + sf::Vector2f(-5, size_.y - 5 - position_.y + 95)));
  roof_.setPoint(1, sf::Vector2f(position_ + sf::Vector2f(20, size_.y + 25 - position_.y + 95)));
  roof_.setPoint(2, sf::Vector2f(position_ + sf::Vector2f(-20 + size_.x, size_.y + 25 - position_.y + 95)));
  roof_.setPoint(3, sf::Vector2f(position_ + sf::Vector2f(5 + size_.x, size_.y - 5 - position_.y + 95)));
  roof_.setFillColor(sf::Color(166, 61, 32));
  roof_.setOutlineColor(sf::Color(0, 0, 0));
  roof_.setOutlineThickness(2);
}

void House::SearchShadow(float tg) {
  shadow_.setPointCount(4);
  if (tg == 0) {
    shadow_.setPoint(0, sf::Vector2f(position_.x, position_.y));
    shadow_.setPoint(1, sf::Vector2f(position_.x, 640));
    shadow_.setPoint(2, sf::Vector2f(position_.x + size_.x, 640));
    shadow_.setPoint(3, sf::Vector2f(position_.x + size_.x, position_.y));
    return;
  }
  shadow_.setPoint(0, sf::Vector2f(position_.x, position_.y + size_.y));
  shadow_.setPoint(1, sf::Vector2f(position_.x, position_.y + size_.y / tg + size_.y));
  shadow_.setPoint(2, sf::Vector2f(position_.x + size_.x, position_.y + size_.y / tg + size_.y));
  shadow_.setPoint(3, sf::Vector2f(position_.x + size_.x, position_.y + size_.y));
}

void House::draw(sf::RenderTexture& window) const {
  sf::RectangleShape rect(size_);
  rect.setPosition(sf::Vector2f(position_.x, 95));
  rect.setFillColor(color_);
  rect.setOutlineColor(sf::Color(0, 0, 0));
  rect.setOutlineThickness(2);
  window.draw(rect);
  window.draw(roof_);
}

void House::drawTop(sf::RenderTexture& window) const {
  sf::RectangleShape rect(size_);
  rect.setPosition(position_);
  rect.setFillColor(sf::Color(166, 61, 32));
  rect.setOutlineColor(sf::Color(0, 0, 0));
  rect.setOutlineThickness(2);
  window.draw(rect);
}

sf::ConvexShape House::getHardShadow(float tg) {
  SearchShadow(tg);
  return shadow_;
}
