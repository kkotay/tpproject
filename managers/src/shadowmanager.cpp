#include "shadowmanager.h"

ShadowManager::ShadowManager(std::vector<Object*>& objects) {
  SetObj(objects);
}

void ShadowManager::SearchShadow(float angle) {
  HardShadow(tan(angle));
  if (angle > 30) {
    SoftShadow(tan(angle));
  }
}

void ShadowManager::HardShadow(float tg) {
  for(auto & object : objects_) {
    object->SearchShadow(tg);
    sf::ConvexShape shad = object->GetShadow();
    std::vector<geometry::Point> verts;
    for (size_t i = 0; i < shad.getPointCount(); ++i) {
      verts.emplace_back(shad.getPoint(i).x, shad.getPoint(i).y);
    }
    geometry::Polygon poly(verts);
    poly.Shell();
    sf::ConvexShape rshad;
    for (size_t i = 0; i < poly.GetCount(); i++) {
      rshad.setPoint(i, sf::Vector2f(poly.GetPoints()[i].Getx(), poly.GetPoints()[i].Gety()));
    }
    allshadow_.push_back(rshad);
  }
}

void ShadowManager::SoftShadow(float tg) {
  for (auto & object : objects_) {
    object->SearchShadow(tg);
    sf::ConvexShape shad = object->GetShadow();
    std::vector<geometry::Point> verts;
    for (size_t i = 0; i < shad.getPointCount(); ++i) {
      verts.emplace_back(shad.getPoint(i).x, shad.getPoint(i).y);
    }
    geometry::Polygon poly(verts);
    poly.ConvexShell();
    sf::ConvexShape rshad;
    for (size_t i = 0; i < poly.GetCount(); i++) {
      rshad.setPoint(i, sf::Vector2f(poly.GetPoints()[i].Getx(), poly.GetPoints()[i].Gety()));
    }
    allsemishadow_.push_back(rshad);
  }
}

void ShadowManager::SetObj(std::vector<Object*>& obj) {
  for (auto & object : obj) {
    objects_.push_back(object);
  }
}

void ShadowManager::Clear() {
  objects_.clear();
  allshadow_.clear();
  allsemishadow_.clear();
}

std::vector<sf::ConvexShape> &ShadowManager::GetAllSh() {
  return allshadow_;
}

std::vector<sf::ConvexShape> &ShadowManager::GetAllSeSh() {
  return allsemishadow_;
}
