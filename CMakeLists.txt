cmake_minimum_required(VERSION 3.26)
project(mydesmos)

set(CMAKE_CXX_STANDARD 17)

add_executable(mydesmos main.cpp
        window/Button.h
        gometry/circle.h
        window/Button.h
        gometry/circle.h
        gometry/vector.h
        window/Button.h
        window/src/textinput.cpp
        window/src/textinput.cpp
        gometry/vector.h
        gometry/iShape.h
        gometry/line.h
        gometry/point.h
        gometry/polygon.h
        gometry/ray.h
        gometry/segment.h
        gometry/src/circle.cpp
        gometry/src/line.cpp
        gometry/src/point.cpp
        gometry/src/polygon.cpp
        gometry/src/ray.cpp
        gometry/src/segment.cpp
        gometry/src/vector.cpp
        window/src/button.cpp
        dacha/object.h
        dacha/house.h
        dacha/house.cpp
        dacha/Tree.h
        dacha/tree.cpp
        dacha/treeFactory.cpp
        dacha/dacha.h
        dacha/dacha.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:SFML/include)
target_link_libraries(mydesmos sfml-system sfml-window sfml-graphics sfml-audio)