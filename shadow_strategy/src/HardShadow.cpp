#include "HardShadow.h"

std::vector<sf::ConvexShape> HardShadow::SearchShadow(std::vector<Object*>& objects, float tg) {
  std::vector<sf::ConvexShape> allshadow;
  for(auto & object : objects) {
    object->SearchShadow(tg);
    sf::ConvexShape shad = object->getShadow();
    std::vector<geometry::Point> vertices;
    for (size_t i = 0; i < shad.getPointCount(); ++i) {
      vertices.emplace_back(shad.getPoint(i).x, shad.getPoint(i).y);
    }
    geometry::Polygon poly(vertices);
    poly.Shell();
    sf::ConvexShape shadow;
    for (size_t i = 0; i < poly.getCount(); i++) {
      shadow.setPoint(i, sf::Vector2f(poly.getPoints()[i].getX(), poly.getPoints()[i].getY()));
    }
    shadow.setFillColor(sf::Color(0, 0, 0));
    allshadow.push_back(shadow);
  }
  return allshadow;
}
