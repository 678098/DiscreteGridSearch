cmake_minimum_required (VERSION 2.6)

project (Samples)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_DEFAULT 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(CMAKE_BUILD_TYPE STREQUAL "")
	set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(Backpack "backpack/main.cpp")
target_link_libraries(Backpack dgs)
