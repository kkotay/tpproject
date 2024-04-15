
#ifndef MYDESMOS_HOUSE_H
#define MYDESMOS_HOUSE_H
#include "object.h"
class House : public Object {
 protected:
  sf::Vector2f size_;
  sf::Color color_;
  void SearchShadow(float) override;

 public:
  House() = default;
  House(sf::Vector2f, sf::Vector2f, sf::Color);
  void draw(sf::RenderTexture&) const override;
  void drawtop(sf::RenderTexture&) const override;
  ~House() = default;
};


#endif //MYDESMOS_HOUSE_H
