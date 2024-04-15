#ifndef DACHA_ELLIPSE_H
#define DACHA_ELLIPSE_H
#include <SFML/Graphics.hpp>
#include <valarray>
#include <cmath>

static const float pi = 3.141592654f;

class Ellipse : public sf::ConvexShape {
 private :
  sf::Vector2f radius_;
  size_t pointcount_ = 32;

 public :
  explicit Ellipse(const sf::Vector2f& = sf::Vector2f(0, 0));
  void setRadius(const sf::Vector2f&);
  const sf::Vector2f& getRadius() const;
  size_t getPointCount() const override;
  virtual sf::Vector2f getPoint(unsigned int index) const;
};


#endif
