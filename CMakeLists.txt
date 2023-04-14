cmake_minimum_required(VERSION 3.1)

project(IcyTower)



include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


add_executable(IcyTower src/main.cpp src/Player.cpp src/Player.h src/Tile.h src/Tile.cpp)
target_link_libraries(IcyTower PRIVATE sfml-graphics sfml-audio)
