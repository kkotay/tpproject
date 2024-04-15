#include <SFML/Graphics.hpp>
#include "managers/cottegemanager.h"

int main() {
  sf::RenderTexture window{};
  window.create(800, 640);
  window.clear(sf::Color::White);
  CottageManager dacha(window);
  dacha.Run();
  return 0;
}