#ifndef MYDESMOS_OBJECT_H
#define MYDESMOS_OBJECT_H
#include <SFML/Graphics.hpp>
#include "ellipse.h"
#include <memory>

class Object {
 protected:
  sf::Vector2f pos_;
  sf::ConvexShape shadow_;

 public:
  void setPosition(const sf::Vector2f pos) {
    pos_ = pos;
  };
  sf::ConvexShape& GetShadow() {
    return shadow_;
  }
  virtual void SearchShadow(float) = 0;
  virtual void draw(sf::RenderTexture&) const{};
  virtual void drawtop(sf::RenderTexture&) const{};
};

#endif
