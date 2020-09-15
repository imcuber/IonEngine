cmake_minimum_required(VERSION 3.15)

project(IonEngine)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/extern")

add_library(IonEngine STATIC "IonEngine.cpp" "include/IonEngine/IonEngine.h" "include/IonEngine/extern/OpenGL.h")
target_include_directories(IonEngine PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include" ${BULLET3_INCLUDE_DIRECTORIES})
target_link_libraries(IonEngine PUBLIC 
	glfw 
	glad 
	glm 
	assimp 
	stb_image 
	imgui
	LinearMath
	Bullet3Common
	BulletInverseDynamics
	BulletCollision
	BulletDynamics
	BulletSoftBody
)