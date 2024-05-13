#ifndef DACHA_BUSH_H
#define DACHA_BUSH_H
#include "Object.h"

class Bush : public Object {
protected:
  sf::Vector2f position_;
  sf::ConvexShape bush_{};
  sf::CircleShape topview_{};

 public:
  Bush() = default;
  Bush(sf::Vector2f, const sf::ConvexShape&, sf::Color, float);
  void draw(sf::RenderTexture&) const override;
  void drawTop(sf::RenderTexture&) const override;
  sf::ConvexShape getHardShadow(float) override;
  void SearchShadow(float) override;
  ~Bush() = default;
};


#endif
