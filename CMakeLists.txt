cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine2 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ./include)
link_directories(./lib)

add_executable(PhysicsEngine2 src/PhysicsEngineMKII.cpp "src/Util/Math/Vector.cpp" "src/Util/Math/Vector.h")
target_link_libraries(PhysicsEngine2 ${OPENGL_LIBRARIES} glfw3 glew32)