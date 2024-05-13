#ifndef DACHA_HARDSHADOW_H
#define DACHA_HARDSHADOW_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "../my_geometry/Polygon.h"

class HardShadow {
 public:
  template<class T>
  std::vector<sf::ConvexShape> SearchShadow(std::vector<T>& objects, float tg) {
    std::vector<sf::ConvexShape> allshadow;
    for(auto & object : objects) {
      sf::ConvexShape shad = object.getHardShadow(tg);
      std::vector<geometry::Point> vertices;
      for (size_t i = 0; i < shad.getPointCount(); ++i) {
        vertices.emplace_back(shad.getPoint(i).x, shad.getPoint(i).y);
      }
      geometry::Polygon polygon(vertices);
      sf::ConvexShape shadow;
      shadow.setPointCount(polygon.getCount());
      for (size_t i = 0; i < polygon.getCount(); i++) {
        shadow.setPoint(i, sf::Vector2f(polygon.getPoints()[i].getX(), polygon.getPoints()[i].getY()));
      }
      shadow.setFillColor(sf::Color(100, 100, 100));
      allshadow.push_back(shadow);
    }
    return allshadow;
  }
};

#endif