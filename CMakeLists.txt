cmake_minimum_required(VERSION 3.22.1)
project(dacha)

set(CMAKE_CXX_STANDARD 17)

include_directories(my_geometry)
include_directories(objects)
include_directories(shadow_strategy)
include_directories(managers)
add_subdirectory("my_geometry")
add_subdirectory("objects")

add_executable(dacha main.cpp
        shadow_strategy/src/ShadowStrategy.cpp
        shadow_strategy/src/HardShadow.cpp
        shadow_strategy/src/SoftShadow.cpp
        managers/src/ShadowManager.cpp
        managers/src/Drawer.cpp
        managers/src/CottegeManager.cpp
)

target_link_libraries(dacha objects)

set(SFML_DIR /usr/include/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(/usr/include/SFML)
target_link_libraries(dacha sfml-system sfml-window sfml-graphics sfml-audio)