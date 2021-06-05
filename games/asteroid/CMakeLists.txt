cmake_minimum_required(VERSION 3.14)

project(chapter02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
    -Wall -Wextra           # Typical baseline
    -Wpedantic              # Non-standard C++ is used

    -Wshadow                # Variable declaration shadows one from a parent scope
    -Wnon-virtual-dtor      # Class with virtual functions has a non-virtual destructor
    -Wold-style-cast        # C-style casts
    -Wcast-align            # Potential errors dereferencing pointers
    -Woverloaded-virtual    # Overload (not override) a virtual function
    -Wconversion            # Type conversions that may lose data
    -Wsign-conversion       # Sign conversions
    -Wdouble-promotion      # float is implicit promoted to double
    -Wformat=2              # Security issues around functions that format output (like printf)
)

add_executable(app
               AssetManager.cpp
               Animator.cpp
               Asteroid.cpp
               SpaceShip.cpp
               Explosion.cpp
               Game.cpp
               main.cpp)

target_link_libraries(app
                      sfml-graphics
                      sfml-window
                      sfml-system)