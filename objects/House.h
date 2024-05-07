#ifndef DACHA_HOUSE_H
#define DACHA_HOUSE_H
#include "Object.h"
class House : public Object {
 protected:
  sf::Vector2f size_;
  sf::Color color_;

 public:
  House() = default;
  House(sf::Vector2f, sf::Vector2f, sf::Color);
  void draw(sf::RenderTexture&) const override;
  void drawTop(sf::RenderTexture&) const override;
  void SearchShadow(float) override;
  ~House() = default;
};

#endif