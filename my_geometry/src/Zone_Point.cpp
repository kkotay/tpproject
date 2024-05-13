#include "../Zone_Point.h"

namespace geometry {
  Zone_Point::Zone_Point() = default;
  Zone_Point::Zone_Point(const Point& a) : point_(a){};
  Point& Zone_Point::getPoint() {
    return point_;
  }

  void Zone_Point::setZone(size_t zone) {
    zone_ = zone;
  }

  size_t Zone_Point::getZone() const {
    return zone_;
  }

  Zone_Point::~Zone_Point() = default;
}