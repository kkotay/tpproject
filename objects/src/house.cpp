#include "../house.h"

House::House(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
  pos_ = pos;
  size_ = size;
  color_ = color;
}

void House::SearchShadow(unsigned int) const {
// coming soon
}

void House::draw(sf::RenderWindow& window) const {
  sf::RectangleShape rect(size_);
  rect.setPosition(pos_);
  rect.setFillColor(color_);
  rect.setOutlineColor(sf::Color(0, 0, 0));
  rect.setOutlineThickness(4);
  window.draw(rect);
}
