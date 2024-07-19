cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine2 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenGL REQUIRED)

include_directories(
	${OPENGL_INCLUDE_DIRS} 
	./include
	./include/imgui/
	
)

link_directories(./lib)

file(GLOB_RECURSE SOURCES 
	"src/*.cpp" 
	"src/Utils/Math/*.cpp" 
	"src/Render/*.cpp" 
	"src/Physics/*.cpp"
	"src/include/imgui/*.cpp"
	"src/include/imgui/backends/*.cpp")


add_executable(PhysicsEngine2 ${SOURCES})
target_link_libraries(PhysicsEngine2 ${OPENGL_LIBRARIES} glfw3 glew32)