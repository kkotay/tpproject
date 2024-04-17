#ifndef DACHA_OBJECT_H
#define DACHA_OBJECT_H
#include <SFML/Graphics.hpp>
#include "../my_geometry/Ellipse.h"
#include <memory>

class Object {
 protected:
  sf::Vector2f position_;
  sf::ConvexShape shadow_;

 public:
  void setPosition(const sf::Vector2f position) {
    position_ = position;
  };
  sf::ConvexShape& getShadow() {
    return shadow_;
  }
  virtual void SearchShadow(float) = 0;
  virtual void draw(sf::RenderTexture&) const{};
  virtual void drawTop(sf::RenderTexture&) const{};
};

#endif
