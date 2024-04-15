#ifndef GOMETRY_LINE_H
#define GOMETRY_LINE_H
#include "vector.h"
#include "point.h"
#include "iShape.h"
namespace geometry {
  class Line : public IShape {
  private:
    float a_ = 0;
    float b_ = 0;
    float c_ = 0;
    Point pon1_;
    Point pon2_;

  public:
    explicit Line();
    explicit Line(const Point&, const Point&) ;
    float Geta() const;
    float Getb() const;
    float Getc() const;
    Point Getpon1() const;
    Point Getpon2() const;
    float DistPoint(const Point& pon) const;
    Line& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
  };
}
#endif //GOMETRY_LINE_H
