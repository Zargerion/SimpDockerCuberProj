cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD 17)
#set(CMAKE_MAKE_PROGRAM make)
#set(CMAKE_C_COMPILER g++)
set(CMAKE_CXX_COMPILER g++)

project(wndth)

find_package(OpenCV REQUIRED)
include_directories($(OpenCV_INCLUDE_DIRS))

add_executable(app  main.cpp)
target_link_libraries(app ${OpenCV_LIBS})