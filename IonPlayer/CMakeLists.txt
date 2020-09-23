cmake_minimum_required(VERSION 3.15)

project(IonPlayer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(IonPlayer "IonPlayer.cpp")
target_link_libraries(IonPlayer PRIVATE IonEngine)
