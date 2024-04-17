#include "Drawer.h"

void Drawer::drawTopView(sf::RenderTexture& window, std::vector<Object*>& objects) {
  for (const auto& object : objects) {
    object->drawTop(window);
  }
}

void Drawer::drawFrontView(sf::RenderTexture& window, std::vector<Object*>& objects) {
  for (const auto& object : objects) {
    object->drawTop(window);
  }
}

void Drawer::drawSimple(sf::RenderTexture& window, std::vector<sf::ConvexShape>& shapes) {
  for (const auto& shape : shapes) {
    window.draw(shape);
  }
}

void Drawer::drawObject(sf::RenderTexture& window, std::vector<Object*>& objects, View view) {
  switch (view) {
    case top:
      drawTopView(window, objects);
      break;
    case front:
      drawFrontView(window, objects);
      break;
  }
}