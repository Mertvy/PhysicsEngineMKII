cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine2 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#if on linux/mac
#sudo apt install glew/glfw3
#brew install glew/glfw3
#then add find_package(glfw3/glew REQUIRED and delete all the precompiled library shit)
find_package(OpenGL REQUIRED)

#includes
include_directories(
	${OPENGL_INCLUDE_DIRS} 
	./include	
	./include/imgui
)

#libraries (not needed on linux or mac)
link_directories(./lib)


#compile and link against these
set(SOURCES
	./include/imgui/backends/imgui_impl_glfw.cpp
	./include/imgui/backends/imgui_impl_opengl3.cpp
	./include/imgui/imgui.cpp
	./include/imgui/imgui_demo.cpp
	./include/imgui/imgui_draw.cpp
	./include/imgui/imgui_tables.cpp
	./include/imgui/imgui_widgets.cpp
	./src/Util/Math/vector.cpp
	./src/PhysicsEngineMKII.cpp
)


add_executable(PhysicsEngine2 ${SOURCES})
target_link_libraries(PhysicsEngine2 ${OPENGL_LIBRARIES} glfw3 glew32)