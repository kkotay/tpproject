#include "shadowmanager.h"

sf::ConvexShape& ShadowManager::GetShape() {
  return allshadow_;
}

ShadowManager::ShadowManager(std::vector<Object*>& objects) : objects_(objects) {};

void ShadowManager::SearchShadow(unsigned int angle) {
  // тут еще надо бы пересечение фигур сначала написать, а уже потом общую тень искать
}

sf::ConvexShape ShadowManager::HardShadow(sf::ConvexShape& shape) {
  geometry::Polygon poly(shape);
  poly.Shell();
  sf::ConvexShape shadow;
  shadow.setPointCount(poly.GetCount());
  for (size_t i = 0; i < poly.GetCount(); ++i) {
    shadow.setPoint(i, sf::Vector2f(poly.GetPoints()[i].Getx(), poly.GetPoints()[i].Gety()));
  }
  return shadow;
}

sf::ConvexShape ShadowManager::SoftShadow(sf::ConvexShape& shape) {
  geometry::Polygon poly(shape);
  poly.ConvexShell();
  sf::ConvexShape shadow;
  shadow.setPointCount(poly.GetCount());
  for (size_t i = 0; i < poly.GetCount(); ++i) {
    shadow.setPoint(i, sf::Vector2f(poly.GetPoints()[i].Getx(), poly.GetPoints()[i].Gety()));
  }
  return shadow;
}
