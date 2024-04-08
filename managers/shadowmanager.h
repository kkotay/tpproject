#ifndef DACHA_SHADOWMANAGER_H
#define DACHA_SHADOWMANAGER_H

#include "SFML/Graphics.hpp"
#include "../objects/tree.h"
#include "../objects/house.h"
#include "../my_gometry/polygon.h"

class ShadowManager {
 protected:
  std::vector<Object*> objects_;
  std::vector<sf::ConvexShape> allshadow_;
  std::vector<sf::ConvexShape> allsemishadow_;
  void HardShadow(float);
  void SoftShadow(float);

 public:
  ShadowManager() = default;
  std::vector<sf::ConvexShape>& GetAllSh();
  std::vector<sf::ConvexShape>& GetAllSeSh();
  explicit ShadowManager(std::vector<Object*>&);
  void SetObj(std::vector<Object*>&);

  void SearchShadow(float);
  void Clear();
  ~ShadowManager() = default;
};
#endif