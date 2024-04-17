#ifndef DACHA_SHADOWSTRATEGY_H
#define DACHA_SHADOWSTRATEGY_H
#include "HardShadow.h"
#include "SoftShadow.h"
#include <cmath>

class ShadowStrategy {
 private:
  HardShadow hard_shadow_{};
  SoftShadow soft_shadow_{};

 public:
  std::vector<sf::ConvexShape> SearchShadow(std::vector<Object*>&, float angle);
};

#endif
