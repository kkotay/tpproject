cmake_minimum_required(VERSION 3.26)
project(my_geometry)

set(CMAKE_CXX_STANDARD 17)

add_library(my_geometry
        src/Vector.cpp
        src/Point.cpp
        src/Zone_Point.cpp
        src/Ray.cpp
        src/Segment.cpp
        src/Line.cpp
        src/Polygon.cpp
        src/Ellipse.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:SFML/include)
target_link_libraries(my_geometry sfml-system sfml-window sfml-graphics sfml-audio)