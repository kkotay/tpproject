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
};


#endif //MYDESMOS_DACHA_H
