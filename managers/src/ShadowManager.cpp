#include "ShadowManager.h"

void ShadowManager::clear() {
  allshadow_.clear();
}

std::vector<sf::ConvexShape> &ShadowManager::GetAllShadow() {
  return allshadow_;
}