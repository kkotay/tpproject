#include "iShape.h"
#include "point.h"
#include "segment.h"
#include "vector.h"
#ifndef GOMETRY_CIRCLE_H
#define GOMETRY_CIRCLE_H
namespace geometry {
  class Circle : public IShape{
   private:
    Point center_;
    int64_t rad_ = 0;
   public:
    Circle();
    Circle(const Point&, const int64_t&);
    Circle& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Circle* Clone() const override;
    std::string ToString() const override;
    ~Circle() override;
  };
}
#endif //GOMETRY_CIRCLE_H
