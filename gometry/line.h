#ifndef GOMETRY_LINE_H
#define GOMETRY_LINE_H
#include "vector.h"
#include "point.h"
#include "iShape.h"
namespace geometry {
  class Line : public IShape {
  private:
    int64_t a_ = 0;
    int64_t b_ = 0;
    int64_t c_ = 0;
    Point pon1_;
    Point pon2_;

  public:
    explicit Line();
    explicit Line(const Point&, const Point&) ;
    int64_t Geta() const;
    int64_t Getb() const;
    int64_t Getc() const;
    Point Getpon1() const;
    Point Getpon2() const;
    int64_t DistPoint(const Point& pon) const;
    Line& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Line* Clone() const override;
    std::string ToString() const override;
  };
}
#endif //GOMETRY_LINE_H
