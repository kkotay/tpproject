#include "drawer.h"

void Drawer::DrawUpView(sf::RenderTexture& window,  std::vector<Object*>& smth) {
  for (auto & i : smth) {
    i->drawtop(window);
  }
}

void Drawer::DrawFrontView(sf::RenderTexture& window,  std::vector<Object*>& smth) {
  for (auto & i : smth) {
    i->draw(window);
  }
}

void Drawer::SimpleDraw(sf::RenderTexture& window, std::vector<sf::ConvexShape>& smth) {
  for (const auto& i : smth) {
    window.draw(i);
  }
}

void Drawer::DrawObject(sf::RenderTexture& window, std::vector<Object*>& smth, view vieww = up) {
  switch (vieww) {
    case up:
      DrawUpView(window, smth);
      break;
    case front:
      DrawFrontView(window, smth);
      break;
  }
}