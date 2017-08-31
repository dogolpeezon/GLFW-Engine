cmake_minimum_required(VERSION 3.0.0)
project(glgame VERSION 0.0.0)

include(CTest)
enable_testing()

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(${usr/include/GL} ${usr/include/GLFW})
add_executable(glgame main.cpp Engine.cpp Keyboard.cpp InputManager.cpp Pyramid.cpp)

target_link_libraries(glgame ${usr/lib64} GLEW)
target_link_libraries(glgame ${usr/lib} GL)
target_link_libraries(glgame ${usr/lib64} glfw3)
target_link_libraries(glgame ${usr/lib} X11)
target_link_libraries(glgame ${usr/lib} Xrandr)
target_link_libraries(glgame ${usr/lib} Xinerama)
target_link_libraries(glgame ${usr/lib} Xxf86vm)
target_link_libraries(glgame ${usr/lib} Xcursor)
target_link_libraries(glgame ${usr/lib} pthread)
target_link_libraries(glgame ${usr/lib} dl)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)