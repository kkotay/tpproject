#include "../house.h"

House::House(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
  pos_ = pos;
  size_ = size;
  color_ = color;
}

void House::SearchShadow(float tg) {
  shadow_.setPointCount(4);
  shadow_.setPoint(0, sf::Vector2f(pos_.x - size_.x / 2, pos_.y));
  shadow_.setPoint(1, sf::Vector2f(pos_.x - size_.x / 2, pos_.y + size_.y / tg));
  shadow_.setPoint(2, sf::Vector2f(pos_.x + size_.x / 2, pos_.y + size_.y / tg));
  shadow_.setPoint(3, sf::Vector2f(pos_.x + size_.x / 2, pos_.y + size_.y));
}

void House::draw(sf::RenderTexture& window) const {
  sf::RectangleShape rect(size_);
  rect.setPosition(pos_);
  rect.setFillColor(color_);
  rect.setOutlineColor(sf::Color(0, 0, 0));
  rect.setOutlineThickness(4);
  window.draw(rect);
}

void House::drawtop(sf::RenderTexture& window) const {
  draw(window);
}