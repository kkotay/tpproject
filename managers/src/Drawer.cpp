#include "Drawer.h"

void Drawer::drawSimple(sf::RenderTexture& window, std::vector<sf::ConvexShape>& shapes) {
  for (const auto& shape : shapes) {
    window.draw(shape);
  }
}