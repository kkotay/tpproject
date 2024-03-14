#ifndef MYDESMOS_TREE_H
#define MYDESMOS_TREE_H
#include "object.h"
#include "../gometry/circle.h"
#include <SFML/Graphics.hpp>

struct treetype {
  enum type {
    cedar,
    appletree,
    fir,
  };
};

class Tree : public Object {
 protected:
  treetype::type type_;
  geometry::Point pos_;
  void setColor(sf::Color);

 public:
  Tree();
  Tree(geometry::Point&, geometry::Circle&, treetype::type type);
  void setSize(int64_t);
  void setPosition(geometry::Point);
  void update() override;
  ~Tree();
};


#endif //MYDESMOS_TREE_H
