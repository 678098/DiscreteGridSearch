cmake_minimum_required (VERSION 2.6)

project (DiscreteGridSearch)

add_definitions(-std=gnu++11)

file (GLOB DGS_CORE ${PROJECT_SOURCE_DIR}/Core/*.cpp)
file (GLOB DGS_SAMPLES ${PROJECT_SOURCE_DIR}/Samples/*.cpp)
file (GLOB DGS_SOLVER ${PROJECT_SOURCE_DIR}/Solver/*.cpp)
file (GLOB DGS_VARIATION ${PROJECT_SOURCE_DIR}/Variation/*.cpp)


include_directories(
${PROJECT_SOURCE_DIR}/Core
${PROJECT_SOURCE_DIR}/Samples
${PROJECT_SOURCE_DIR}/Solver
${PROJECT_SOURCE_DIR}/Variation
)


set (SOURCE "${DGS_CORE};${DGS_SAMPLES};${DGS_SOLVER};${DGS_VARIATION};")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g3")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g3")


add_executable(DiscreteGridSearch ${SOURCE})
target_link_libraries(DiscreteGridSearch)
