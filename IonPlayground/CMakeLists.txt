cmake_minimum_required(VERSION 3.15)

project(IonPlayground)

add_executable(IonPlayground "IonPlayground.cpp")
target_link_libraries(IonPlayground PRIVATE IonEngine)
