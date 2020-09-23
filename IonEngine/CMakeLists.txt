cmake_minimum_required(VERSION 3.15)

project(IonEngine)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/extern")

add_library(IonEngine STATIC "source/IonEngine.cpp" "include/IonEngine.h" "include/IonEngine/extern/OpenGL.h" "include/IonEngine/extern/fmtlib.h" "include/IonEngine/Utility/Logger.h" "source/Utility/Logger.cpp" "include/IonEngine/Core.h" "include/IonEngine/Utility.h" "include/IonEngine/Application.h"  "source/Application.cpp" "include/IonEngine/Utility/Clock.h" "source/Utility/Clock.cpp" "include/IonEngine/Events.h" "include/IonEngine/Events/ApplicationEvents.h" "include/IonEngine/Events/WindowEvents.h" "include/IonEngine/Events/InputEvents.h" "source/Events/Events.cpp" "source/Events/ApplicationEvents.cpp" "source/Events/InputEvents.cpp" "source/Events/WindowEvents.cpp" "include/IonEngine/Input.h" "include/IonEngine/Events/InputEvents/KeyboardEvents.h" "include/IonEngine/Events/InputEvents/MouseEvents.h" "source/Events/InputEvents/KeyboardEvents.cpp" "source/Events/InputEvents/MouseEvents.cpp" "include/IonEngine/Window.h" "source/Window.cpp" "source/Platform/CrossPlatform/CrossPlatformWindow.cpp" "source/Platform/CrossPlatform/CrossPlatformInput.cpp")
target_include_directories(IonEngine PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include" ${BULLET3_INCLUDE_DIRECTORIES})
target_link_libraries(IonEngine PUBLIC 
	glfw 
	glad 
	glm 
	assimp 
	stb_image 
	imgui
	fmt
	sol2
	LinearMath
	Bullet3Common
	BulletInverseDynamics
	BulletCollision
	BulletDynamics
	BulletSoftBody
)
