cmake_minimum_required(VERSION 3.15)

project(IonEngine)

# glfw
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
option(GLFW_BUILD_DOCS OFF)
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/glfw")

# glad
add_library(glad STATIC "${CMAKE_CURRENT_LIST_DIR}/glad/src/glad.c")
target_include_directories(glad PUBLIC "${CMAKE_CURRENT_LIST_DIR}/glad/include")

# glm
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/glm")

# imgui
set(IMGUI_SOURCE
	"${CMAKE_CURRENT_LIST_DIR}/imgui/imgui.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_demo.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_draw.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/imgui/imgui_widgets.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/imgui/examples/imgui_impl_opengl3.cpp"
	"${CMAKE_CURRENT_LIST_DIR}/imgui/examples/imgui_impl_glfw.cpp"
)
add_library(imgui STATIC ${IMGUI_SOURCE})
target_include_directories(imgui PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(imgui PRIVATE "${CMAKE_CURRENT_LIST_DIR}/imgui")
target_link_libraries(imgui PRIVATE glad glfw)

# assimp
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/assimp")

# stb_image
add_library(stb_image STATIC "${CMAKE_CURRENT_LIST_DIR}/stb_image/stb_image_impl.cpp")
target_include_directories(stb_image PUBLIC "${CMAKE_CURRENT_LIST_DIR}/stb_image")

# bullet3
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/bullet3")
set(BULLET3_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/bullet3/src" PARENT_SCOPE)
