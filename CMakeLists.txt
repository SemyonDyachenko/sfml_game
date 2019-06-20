cmake_minimum_required(VERSION 3.14)
project(CatchOnBubble)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(CatchOnBubble src/main.cpp src/Player.cpp src/Player.h src/Map.h)

target_link_libraries(CatchOnBubble sfml-graphics sfml-audio)