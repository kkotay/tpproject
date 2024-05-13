#include "Bush.h"

Bush::Bush(sf::Vector2f position, const sf::ConvexShape& bush, sf::Color color, float radius) {
  position_ = position;
  bush_ = bush;
  bush_.setFillColor(color);
  bush_.setOutlineColor(sf::Color(color.r, color.g - 10, color.b - 10));
  bush_.setOutlineThickness(3);
  topview_ = sf::CircleShape(radius);
  topview_.setFillColor(color);
  topview_.setPosition(position_ - sf::Vector2f(20, 20));
  topview_.setOutlineThickness(3);
  topview_.setOutlineColor(sf::Color(color.r, color.g - 10, color.b - 10));
}

void Bush::draw(sf::RenderTexture& window) const {
  window.draw(bush_);
}

void Bush::drawTop(sf::RenderTexture& window) const {
  window.draw(topview_);
}

void Bush::SearchShadow(float tg) {
  if (tg == 0) {
    shadow_.setPointCount(bush_.getPointCount());
    for (size_t i = 0; i < 5; ++i) {
      if (bush_.getPoint(i).y == 85) {
        shadow_.setPoint(i, (sf::Vector2f(bush_.getPoint(i).x, 85)));
      } else {
        shadow_.setPoint(i, (sf::Vector2f(bush_.getPoint(i).x, 640)));
      }
    }
    return;
  }
  int count = 32;
  shadow_.setPointCount(bush_.getPointCount() * count);
  sf::CircleShape circle;
  circle.setPointCount(count);
  circle.setPosition(position_);
  for (size_t i = 0; i < bush_.getPointCount(); ++i) {
    float radius = std::fabs(bush_.getPoint(i).x - position_.x);
    circle.setRadius(std::fabs(radius));
    for (size_t j = 0; j < count; ++j) {
      shadow_.setPoint(i * count + j,
                       (sf::Vector2f(circle.getPoint(j).x + position_.x - radius,
                                     position_.y + circle.getPoint(j).y - radius + (bush_.getPoint(i).y - 85) / tg)));
    }
  }
}

sf::ConvexShape Bush::getHardShadow(float tg) {
  sf::ConvexShape shadow;
  shadow.setPointCount(bush_.getPointCount());
  if (tg == 0) {
    for (size_t i = 0; i < shadow.getPointCount(); ++i) {
      if (bush_.getPoint(i).y == 85) {
        shadow.setPoint(i, (sf::Vector2f(bush_.getPoint(i).x, 85)));
      } else {
        shadow.setPoint(i, (sf::Vector2f(bush_.getPoint(i).x, 640)));
      }
    }
    return shadow;
  }
  for (size_t i = 0; i < bush_.getPointCount(); ++i) {
    shadow.setPoint(i, (sf::Vector2f(bush_.getPoint(i).x, position_.y + (bush_.getPoint(i).y - 85) / tg)));
  }
  return shadow;
}
