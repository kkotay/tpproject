#ifndef DACHA_DRAWER_H
#define DACHA_DRAWER_H
#include "SFML/Graphics.hpp"
#include "Object.h"

enum View {
 top,
 front
};

class Drawer {
 private:
  void drawTopView(sf::RenderTexture&, std::vector<Object*>&);
  void drawFrontView(sf::RenderTexture&, std::vector<Object*>&);

 public:
  Drawer() = default;
  void drawSimple(sf::RenderTexture&, std::vector<sf::ConvexShape>&);
  void drawObject(sf::RenderTexture&, std::vector<Object*>&, View = top);
  ~Drawer() = default;
};

#endif