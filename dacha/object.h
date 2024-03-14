#ifndef MYDESMOS_OBJECT_H
#define MYDESMOS_OBJECT_H
#include <SFML/Graphics.hpp>
#include "../gometry/iShape.h"
class Object {
 protected:
  sf::Shape* figure{};
  virtual void update() = 0;
};
#endif //MYDESMOS_OBJECT_H
