#ifndef DACHA_SHADOWMANAGER_H
#define DACHA_SHADOWMANAGER_H

#include "SFML/Graphics.hpp"
#include "../objects/Tree.h"
#include "../objects/House.h"
#include "../my_geometry/Polygon.h"
#include "ShadowStrategy.h"

class ShadowManager {
 protected:
  std::vector<sf::ConvexShape> allshadow_;
  ShadowStrategy shadow_searcher_;

 public:
  ShadowManager() = default;
  std::vector<sf::ConvexShape>& GetAllShadow();

  template<class T>
  void SearchShadow(float angle, std::vector<T>& objects) {
    std::vector<sf::ConvexShape> shadow = shadow_searcher_.SearchShadow(objects, angle);
    for (const auto& i : shadow) {
      allshadow_.push_back(i);
    }
  }

  void clear();
  ~ShadowManager() = default;
};

#endif