cmake_minimum_required(VERSION 3.22.1)
project(objects)

set(CMAKE_CXX_STANDARD 17)
include_directories("../my_geometry")
add_library(objects
        src/Tree.cpp
        src/House.cpp
        src/FirTree.cpp
        src/AppleTree.cpp
        src/CedarTree.cpp
        src/HouseFactory.cpp
        src/FirFactory.cpp
        src/CedarFactory.cpp
        src/AppleFactory.cpp
        src/TreeFactory.cpp
        src/Bush.cpp
        src/BushFactory.cpp
)

target_link_libraries(objects my_geometry)