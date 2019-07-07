cmake_minimum_required(VERSION 2.6)

project(DiscreteGridSearch)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_DEFAULT 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(CMAKE_BUILD_TYPE STREQUAL "")
	set(CMAKE_BUILD_TYPE Release)
endif()

set(DGS_SOURCES
	"Core/Problem.cpp"
	"Solver/GlobalOptimizationSolver.cpp"
)

include_directories(
	"."
)

add_library(dgs STATIC ${DGS_SOURCES})
target_link_libraries(dgs)

add_subdirectory(Samples)