cmake_minimum_required(VERSION 3.15)

project(IonEditor LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(IonEditor "${CMAKE_CURRENT_LIST_DIR}/IonEditor.cpp" "source/Application.cpp" "include/Application.h" "include/EditorLayer.h" "source/EditorLayer.cpp")
target_include_directories(IonEditor PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include")
target_link_libraries(IonEditor PRIVATE IonEngine)
