#include <SFML/Graphics.hpp>
#include "managers/CottegeManager.h"

int main() {
  sf::RenderTexture window{};
  window.create(800, 640);
  window.clear(sf::Color::White);
  CottageManager dacha(window);
  dacha.run();
  return 0;
}