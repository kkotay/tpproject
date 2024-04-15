cmake_minimum_required(VERSION 3.26)
project(managers)

set(CMAKE_CXX_STANDARD 17)

include_directories(managers)
include_directories(my_gometry)
include_directories(window)
include_directories(objects)

add_executable(managers main.cpp
        objects/src/house.cpp
        objects/src/tree.cpp
        objects/src/firtree.cpp
        objects/src/appletree.cpp
        objects/src/cedartree.cpp
        objects/src/applefactory.cpp
        objects/src/firfactory.cpp
        objects/src/cedarfactory.cpp
        managers/src/cottegemanager.cpp
        my_gometry/point.h
        my_gometry/vector.h
        my_gometry/ray.h
        my_gometry/line.h
        my_gometry/polygon.h
        my_gometry/zone_point.h

        my_gometry/src/vector.cpp
        my_gometry/src/point.cpp
        my_gometry/src/ray.cpp
        my_gometry/src/line.cpp
        my_gometry/src/polygon.cpp
        my_gometry/src/zone_point.cpp
        my_gometry/ellipse.h
        managers/src/shadowmanager.cpp
        objects/src/treefactory.cpp
        objects/src/housefactory.cpp
        managers/src/drawer.cpp
        objects/applefactory.h
        my_gometry/src/ellipse.cpp
        my_gometry/src/segment.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:SFML/include)
target_link_libraries(managers sfml-system sfml-window sfml-graphics sfml-audio)