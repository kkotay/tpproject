#include "../House.h"

House::House(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
  position_ = pos;
  size_ = size;
  color_ = color;
}

void House::SearchShadow(float tg) {
  shadow_.setPointCount(4);
  shadow_.setPoint(0, sf::Vector2f(position_.x - size_.x / 2, position_.y));
  shadow_.setPoint(1, sf::Vector2f(position_.x - size_.x / 2, position_.y + size_.y / tg));
  shadow_.setPoint(2, sf::Vector2f(position_.x + size_.x / 2, position_.y + size_.y / tg));
  shadow_.setPoint(3, sf::Vector2f(position_.x + size_.x / 2, position_.y + size_.y));
}

void House::draw(sf::RenderTexture& window) const {
  sf::RectangleShape rect(size_);
  rect.setPosition(position_);
  rect.setFillColor(color_);
  rect.setOutlineColor(sf::Color(0, 0, 0));
  rect.setOutlineThickness(4);
  window.draw(rect);
}

void House::drawTop(sf::RenderTexture& window) const {
  draw(window);
}