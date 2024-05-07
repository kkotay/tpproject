#ifndef DACHA_SOFTSHADOW_H
#define DACHA_SOFTSHADOW_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "../my_geometry/Polygon.h"

class SoftShadow {
public:
  template<class T>
  std::vector<sf::ConvexShape> SearchShadow(std::vector<T>& objects, float tg) {
    std::vector<sf::ConvexShape> allshadow;
    for (auto & object : objects) {
      object.SearchShadow(tg);
      sf::ConvexShape shadow = object.getShadow();
      std::vector<geometry::Point> vertices;
      for (size_t i = 0; i < shadow.getPointCount(); ++i) {
        vertices.emplace_back(shadow.getPoint(i).x, shadow.getPoint(i).y);
      }
      geometry::Polygon polygon(vertices);
      polygon.ConvexShell();
      sf::ConvexShape semishadow;
      semishadow.setPointCount(polygon.getCount());
      for (size_t i = 0; i < polygon.getCount(); i++) {
        semishadow.setPoint(i, sf::Vector2f(polygon.getPoints()[i].getX(), polygon.getPoints()[i].getY()));
      }
      semishadow.setFillColor(sf::Color(80, 80, 80));
      allshadow.push_back(semishadow);
    }
    for(auto & object : objects) {
      object.SearchShadow(tg);
      sf::ConvexShape shad = object.getShadow();
      std::vector<geometry::Point> vertices;
      for (size_t i = 0; i < shad.getPointCount(); ++i) {
        vertices.emplace_back(shad.getPoint(i).x, shad.getPoint(i).y);
      }
      geometry::Polygon polygon(vertices);
      polygon.Shell();
      sf::ConvexShape shadow;
      shadow.setPointCount(polygon.getCount());
      for (size_t i = 0; i < polygon.getCount(); i++) {
        shadow.setPoint(i, sf::Vector2f(polygon.getPoints()[i].getX(), polygon.getPoints()[i].getY()));
      }
      shadow.setFillColor(sf::Color(50, 50, 50));
      allshadow.push_back(shadow);
    }
    return allshadow;
  }
};

#endif