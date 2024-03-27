//
// Created by kkotay on 22.03.2024.
//

#include "zone_point.h"

namespace geometry {
  Zone_point::Zone_point() = default;
  Zone_point::Zone_point(const Point& a) : a_(a){};
  Point& Zone_point::Getpon() {
    return a_;
  }

  void Zone_point::Setzone(size_t a) {
    zone_ = a;
  }

  size_t Zone_point::Getzone() {
    return zone_;
  }

  Zone_point::~Zone_point() = default;
} // geometry