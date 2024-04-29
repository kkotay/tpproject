#ifndef DACHA_SHADOWMANAGER_H
#define DACHA_SHADOWMANAGER_H

#include "SFML/Graphics.hpp"
#include "../objects/Tree.h"
#include "../objects/House.h"
#include "../my_geometry/Polygon.h"
#include "ShadowStrategy.h"

class ShadowManager {
 protected:
  std::vector<Object*> objects_;
  std::vector<sf::ConvexShape> allshadow_;
  ShadowStrategy shadow_searcher_;

 public:
  ShadowManager() = default;
  std::vector<sf::ConvexShape>& GetAllShadow();
  explicit ShadowManager(std::vector<Object*>&);
  void setObjects(std::vector<Object*>&);
  void SearchShadow(float);
  void clear();
  ~ShadowManager() = default;
};

#endif