
#ifndef MYDESMOS_HOUSE_H
#define MYDESMOS_HOUSE_H
#include "object.h"
#include "../gometry/point.h"
#include "../gometry/polygon.h"
class House : public Object {
 protected:
  sf::Vector2<int64_t> size_;
  sf::Vector2<int64_t> position_;

 public:
  House();
  House(sf::Vector2<int64_t>, sf::Vector2<int64_t>);
  void setSize(sf::Vector2<int64_t>);
  void setPosition(sf::Vector2<int64_t>);
  void update() override;
  ~House();
};


#endif //MYDESMOS_HOUSE_H
