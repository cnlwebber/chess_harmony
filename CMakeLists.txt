# ## (ctrl+/)

# ## Specify CMake version
cmake_minimum_required(VERSION 3.10)
# ## Name the project
project(cmake_template)
# ## Define the executable and source files 
# add_executable(<output_name> <source_files>) 
# ## Specify C++ standard required for *libraries/src code *most likely libraries
set(CMAKE_CXX_STANDARD 23) # Use C++XX
set(CMAKE_CXX_STANDARD_REQUIRED ON) # enforces above variable

