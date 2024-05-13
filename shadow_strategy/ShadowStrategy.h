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
  template<class T>
  std::vector<sf::ConvexShape> SearchShadow(std::vector<T>& objects, float angle) {
    if (angle > 30) {
      return soft_shadow_.SearchShadow(objects, std::tan(angle));
    }
    return hard_shadow_.SearchShadow(objects, std::tan(angle));
  }

};

#endif
