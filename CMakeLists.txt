# MIT License

# Copyright (c) 2018 Benjamin Bercovici and Jay McMahon

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# @file   CMakeLists.txt
# @Author Benjamin Bercovici (bebe0705@colorado.edu)
# @date   March, 2018
# @brief  CMake listing enabling compilation and installation of the SHARMLib library

################################################################################
#
#
# 		The following should normally not require any modification
# 				Unless new files are added to the build tree
#
#
################################################################################

cmake_minimum_required(VERSION 3.0)

get_filename_component(dirName ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(LIB_NAME SHARMLib)

project(${LIB_NAME})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/source/cmake)

# Compiler flags
add_definitions(-Wall -O2 )

# Include directories
include_directories(include)


# Find Armadillo 
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

# Add source files in root directory
add_library(${LIB_NAME} SHARED source/SHARMLib.cpp)
set(library_dependencies ${ARMADILLO_LIBRARIES})

target_link_libraries(${LIB_NAME} ${library_dependencies})

# If ${BREW} is true, installing from homebrew formula
if(NOT BREW)
	install (TARGETS ${LIB_NAME} DESTINATION /usr/local/lib/)
	install (FILES ${PROJECT_SOURCE_DIR}/include/SHARMLib.hpp DESTINATION /usr/local/include/)
	install (DIRECTORY ${PROJECT_SOURCE_DIR}/${LIB_NAME} DESTINATION /usr/local/share)
endif()








