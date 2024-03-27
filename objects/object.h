#ifndef MYDESMOS_OBJECT_H
#define MYDESMOS_OBJECT_H
#include <SFML/Graphics.hpp>
#include "ellipse.h"

class Object {
 protected:
  sf::Vector2f pos_;
  virtual void SearchShadow(unsigned int) const = 0;

 public:
  // virtual void update(sf::RenderWindow&) const = 0;
  void setPosition(const sf::Vector2f pos) {
    pos_ = pos;
  };

  virtual void draw(sf::RenderWindow&) const = 0;

};
#endif
