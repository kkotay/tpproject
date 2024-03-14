#include "iShape.h"
#include "vector.h"
#ifndef GOMETRY_POINT_Hui
#define GOMETRY_POINT_Hui
namespace geometry {
  class Point : public IShape {
  private:
    int64_t x_ = 0;
    int64_t y_ = 0;

  public:
    Point();
    Point(const int64_t&, const int64_t&); // NOLINT
    int64_t Getx() const;
    int64_t Gety() const;
    Point& Move(const Vector&) override;
    bool operator==(const Point&) const;
    Point& operator+=(const Vector&);
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Point* Clone() const override;
    std::string ToString() const override;
    Vector operator-(const Point&) const;
  };
}
#endif
//#include "iShape.h"