#ifndef MYDESMOS_DACHA_H
#define MYDESMOS_DACHA_H
#include "house.h"
#include "Tree.h"
#include "treeFactory.cpp"

class dacha {
private:
  TreeFactory trFactory;
public:
  Tree MakeTree(treetype::type type);
  House MakeHouse();
  void update(sf::RenderWindow& window);
};


#endif //MYDESMOS_DACHA_H
