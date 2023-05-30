cmake_minimum_required(VERSION 3.1)

project(IcyTower)

#set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_BUILD_TYPE "Release")

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(IcyTower src/main.cpp src/Player.cpp src/Player.h src/Tile.h src/Tile.cpp src/Game.h src/Game.cpp src/TextureManager.cpp src/MainMenu.cpp src/MainMenu.h src/UIButton.cpp src/UIButton.h src/EndGame.cpp src/EndGame.h)
target_link_libraries(IcyTower sfml-graphics sfml-audio)


add_executable(all_test
        src/Player.cpp
        src/Player.h
        src/Tile.h
        src/Tile.cpp
        src/Game.h
        src/Game.cpp
        src/TextureManager.cpp
        src/MainMenu.cpp
        src/MainMenu.h
        src/UIButton.cpp
        src/UIButton.h
        src/EndGame.cpp
        src/EndGame.h
        tests/catch.hpp tests/test_main.cpp tests/test_texture_manager.cpp
        )
target_link_libraries(all_test sfml-graphics sfml-audio)
