cmake_minimum_required(VERSION 3.15)

project(IonEngine)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/extern")

add_library(IonEngine STATIC 
	"source/IonEngine.cpp"
	"source/Application.cpp"
	"source/Events.cpp"
	"source/Input.cpp"
	"source/LayerStack.cpp"
	"source/Window.cpp"
	"source/Events/ApplicationEvents.cpp"
	"source/Events/InputEvents.cpp"
	"source/Events/WindowEvents.cpp"
	"source/Events/InputEvents/KeyboardEvents.cpp"
	"source/Events/InputEvents/MouseEvents.cpp"
	"source/Graphics/Context.cpp"
	"source/Graphics/Shader.cpp"
	"source/Platform/API.cpp"
	"source/Platform/Input/GLInput.cpp"
	"source/Platform/Window/GLWindow.cpp"
	"source/Platform/OpenGL/OpenGLContext.cpp"
	"source/Platform/OpenGL/OpenGLShader.cpp"
	"source/Utility/Clock.cpp"
	"source/Utility/Logger.cpp"
 "include/IonEngine/ImGuiLayer.h" "include/IonEngine/Platform/OpenGL/OpenGLImGuiLayer.h" "source/Platform/OpenGL/OpenGLImGuiLayer.cpp" "source/ImGuiLayer.cpp" "include/IonEngine/Graphics/Buffer.h" "source/Graphics/Buffer.cpp" "include/IonEngine/Platform/OpenGL/OpenGLBuffer.h" "source/Platform/OpenGL/OpenGLBuffer.cpp" "include/IonEngine/Graphics/Renderer.h")
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
