#ifndef MYDESMOS_DACHA_H
#define MYDESMOS_DACHA_H
#include "../objects/treefactory.h"
#include "../objects/housefactory.h"
#include "shadowmanager.h"
#include "drawer.h"
#include <iostream>

class CottageManager {
 private:
  sf::RenderTexture& window_;
  TreeFactory trFactory_{};
  HouseFactory hFactory_{};
  Drawer drawer_{};
  ShadowManager shadows_{};
  float angle_ = 0;
  void Command();

 public:
  void Run();
  CottageManager() = default;
  explicit CottageManager(sf::RenderTexture&);
  ~CottageManager() = default;
};
#endif