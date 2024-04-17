#ifndef DACHA_HARDSHADOW_H
#define DACHA_HARDSHADOW_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "../my_geometry/Polygon.h"

class HardShadow {
 public:
  std::vector<sf::ConvexShape> SearchShadow(std::vector<Object*>&, float);
};

#endif