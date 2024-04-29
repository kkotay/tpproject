#include "ShadowManager.h"

ShadowManager::ShadowManager(std::vector<Object*>& objects) {
  setObjects(objects);
}

void ShadowManager::SearchShadow(float angle) {
  allshadow_ = shadow_searcher_.SearchShadow(objects_, angle);
}

void ShadowManager::setObjects(std::vector<Object*>& objects) {
  clear();
  for (auto & object : objects) {
    objects_.push_back(object);
  }
}

void ShadowManager::clear() {
  objects_.clear();
  allshadow_.clear();
}

std::vector<sf::ConvexShape> &ShadowManager::GetAllShadow() {
  return allshadow_;
}