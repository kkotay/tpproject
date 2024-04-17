#include "SoftShadow.h"

std::vector<sf::ConvexShape> SoftShadow::SearchShadow(std::vector<Object*>& objects, float tg) {
  std::vector<sf::ConvexShape> allshadow;
  for (auto & object : objects) {
    object->SearchShadow(tg);
    sf::ConvexShape shadow = object->getShadow();
    std::vector<geometry::Point> vertices;
    for (size_t i = 0; i < shadow.getPointCount(); ++i) {
      vertices.emplace_back(shadow.getPoint(i).x, shadow.getPoint(i).y);
    }
    geometry::Polygon polygon(vertices);
    polygon.ConvexShell();
    sf::ConvexShape semishadow;
    for (size_t i = 0; i < polygon.getCount(); i++) {
      semishadow.setPoint(i, sf::Vector2f(polygon.getPoints()[i].getX(), polygon.getPoints()[i].getY()));
    }
    shadow.setFillColor(sf::Color(50, 50, 50));
    allshadow.push_back(semishadow);
  }
  for(auto & object : objects) {
    object->SearchShadow(tg);
    sf::ConvexShape shad = object->getShadow();
    std::vector<geometry::Point> vertices;
    for (size_t i = 0; i < shad.getPointCount(); ++i) {
      vertices.emplace_back(shad.getPoint(i).x, shad.getPoint(i).y);
    }
    geometry::Polygon polygon(vertices);
    polygon.Shell();
    sf::ConvexShape shadow;
    for (size_t i = 0; i < polygon.getCount(); i++) {
      shadow.setPoint(i, sf::Vector2f(polygon.getPoints()[i].getX(), polygon.getPoints()[i].getY()));
    }
    shadow.setFillColor(sf::Color(0, 0, 0));
    allshadow.push_back(shadow);
  }
  return allshadow;
}
