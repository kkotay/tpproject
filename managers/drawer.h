#ifndef DACHA_DRAWER_H
#define DACHA_DRAWER_H
#include "SFML/Graphics.hpp"

enum view {
 up,
 front
};

class Drawer {
 private:
  view howshow_ = up;
  template<class T>
  void DrawUpView(sf::RenderWindow&, T&);

  template<class T>
  void DrawFrontView(sf::RenderWindow&, T&);

 public:
  Drawer() = default;
  template<class T>
  void DrawObject(sf::RenderWindow&, T&);
  void SetView(view);
  ~Drawer() = default;
};



#endif
