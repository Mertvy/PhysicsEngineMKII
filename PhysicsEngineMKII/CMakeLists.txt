# CMakeList.txt : CMake project for PhysicsEngineMKII, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (PhysicsEngineMKII "PhysicsEngineMKII.cpp" "PhysicsEngineMKII.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PhysicsEngineMKII PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
