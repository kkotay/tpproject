#ifndef DACHA_SHADOWMANAGER_H
#define DACHA_SHADOWMANAGER_H
#include "SFML/Graphics.hpp"
#include "../objects/object.h"
#include "../my_gometry/polygon.h"
class ShadowManager {
 protected:
  std::vector<Object*> objects_;
  sf::ConvexShape allshadow_;
  sf::ConvexShape HardShadow(sf::ConvexShape&);
  sf::ConvexShape SoftShadow(sf::ConvexShape&);

 public:
    ShadowManager() = default;
    sf::ConvexShape& GetShape();
    ShadowManager(std::vector<Object*>&);
    void SearchShadow(unsigned int);
    ~ShadowManager() = default;
};
#endif