#ifndef MYDESMOS_DACHA_H
#define MYDESMOS_DACHA_H
#include "../objects/treefactory.h"
#include "../objects/housefactory.h"
#include "shadowmanager.h"
#include "drawer.h"
#include <iostream>

class CottageManager {
 private:
  sf::RenderWindow& window_;
  TreeFactory trFactory_;
  HouseFactory hFactory_;
  ShadowManager shadows_;
  Drawer drawer_;
  std::vector<Object*> allobjects_;
  void Command();

 public:
  CottageManager() = default;
  CottageManager(sf::RenderWindow&);
  ~CottageManager() = default;
};


#endif