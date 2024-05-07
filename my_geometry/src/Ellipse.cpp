#include "../Ellipse.h"

Ellipse::Ellipse(const sf::Vector2f& radius) : radius_(radius) {}

void Ellipse::setRadius(const sf::Vector2f& radius) {
  radius_ = radius;
  update();
}

const sf::Vector2f& Ellipse::getRadius() const {
  return radius_;
}

size_t Ellipse::getPointCount() const {
  return pointcount_;
}

sf::Vector2f Ellipse::getPoint(unsigned int index) const {
  float angle = index * 2 * pi / getPointCount() - pi / 2;
  float x = std::cos(angle) * radius_.x;
  float y = std::sin(angle) * radius_.y;
  return {radius_.x + x, radius_.y + y};
}