#ifndef DACHA_SOFTSHADOW_H
#define DACHA_SOFTSHADOW_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "../my_geometry/Polygon.h"

class SoftShadow {
public:
  std::vector<sf::ConvexShape> SearchShadow(std::vector<Object*>&, float);
};

#endif