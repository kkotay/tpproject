#ifndef DACHA_DRAWER_H
#define DACHA_DRAWER_H
#include "SFML/Graphics.hpp"
#include "../objects/object.h"

enum view {
 up,
 front
};

class Drawer {
 private:
  void DrawUpView(sf::RenderTexture&, std::vector<Object*>&);
  void DrawFrontView(sf::RenderTexture&, std::vector<Object*>&);

 public:
  Drawer() = default;
  void SimpleDraw(sf::RenderTexture&, std::vector<sf::ConvexShape>&);
  void DrawObject(sf::RenderTexture&, std::vector<Object*>&, view);
  ~Drawer() = default;
};
#endif