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
  template<class T>
  void drawTopView(sf::RenderTexture& window, std::vector<T>& objects) {
    for (const auto& object : objects) {
      object.drawTop(window);
    }
  }

  template<class T>
  void drawFrontView(sf::RenderTexture& window, std::vector<T>& objects) {
    for (const auto& object : objects) {
      object.draw(window);
    }
  }

 public:
  Drawer() = default;
  void drawTopWindow(sf::RenderTexture&);
  void drawFrontWindow(sf::RenderTexture&);
  void drawSimple(sf::RenderTexture&, std::vector<sf::ConvexShape>&);

  template<class T>
  void drawObject(sf::RenderTexture& window, std::vector<T>& objects, View view) {
    switch (view) {
      case top:
        drawTopView(window, objects);
        break;
      case front:
        drawFrontView(window, objects);
        break;
    }
  }

  ~Drawer() = default;
};

#endif