#include "Drawer.h"

void Drawer::drawSimple(sf::RenderTexture& window, std::vector<sf::ConvexShape>& shapes) {
  for (const auto& shape : shapes) {
    window.draw(shape);
  }
}

void Drawer::drawTopWindow(sf::RenderTexture& window) {
  sf::RectangleShape earth(sf::Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));
  earth.setFillColor(sf::Color(123,126,62));
  window.draw(earth);
}

void Drawer::drawFrontWindow(sf::RenderTexture& window) {
  sf::CircleShape sun(30, 32);
  sun.setFillColor(sf::Color(255,249,23));
  sun.setOutlineColor(sf::Color(235,229,3));
  sun.setOutlineThickness(3);
  sun.setPosition(500, 500);
  sf::RectangleShape earth(sf::Vector2f(static_cast<float>(window.getSize().x), 100));
  sf::RectangleShape sky(sf::Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y - 95)));
  earth.setFillColor(sf::Color(123,126,62));
  sky.setPosition(sf::Vector2f(0, 95));
  sky.setFillColor(sf::Color(117,187,253));
  window.draw(earth);
  window.draw(sky);
  window.draw(sun);
}
