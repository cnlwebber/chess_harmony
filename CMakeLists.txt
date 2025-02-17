# ## Specify CMake version
cmake_minimum_required(VERSION 3.10)
# ## Name the project
project(harmony)
# ## Define the executable name and source files 
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(harmony ${SOURCES})
# ## Include headers
include_directories(${PROJECT_SOURCE_DIR}/include)
# ## Specify C++ standard required for *libraries/src code *most likely libraries
set(CMAKE_CXX_STANDARD 23) # Use C++XX
set(CMAKE_CXX_STANDARD_REQUIRED ON) # enforces above variable

# Define a DEBUG flag when building in Debug mode. May also be used for certain os build etc.
# specifpy build type: cmake -DCMAKE_BUILD_TYPE=Debug .
# if(CMAKE_BUILD_TYPE STREQUAL "Debug")   
#   target_compile_definitions(harmony PRIVATE DEBUG)
# endif() 
