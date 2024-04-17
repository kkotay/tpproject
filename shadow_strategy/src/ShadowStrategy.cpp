#include "../ShadowStrategy.h"

std::vector<sf::ConvexShape> ShadowStrategy::SearchShadow(std::vector<Object*>& objects, float angle) {
  if (angle > 30) {
    return soft_shadow_.SearchShadow(objects, std::tan(angle));
  }
  return hard_shadow_.SearchShadow(objects, std::tan(angle));
}
