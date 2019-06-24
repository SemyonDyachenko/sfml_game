cmake_minimum_required(VERSION 3.14)
project(CatchOnBubble)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics audio)
find_package(OpenGL)
find_package(GLUT)


add_executable(CatchOnBubble src/main.cpp src/Player.cpp src/Player.h src/Game.cpp src/Game.h src/MainMenuState.cpp src/MainMenuState.h src/State.cpp src/State.h src/GameState.cpp src/GameState.h src/Button.cpp src/Button.h src/Bullet.cpp src/Bullet.h)

target_link_libraries(CatchOnBubble sfml-graphics sfml-audio ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )