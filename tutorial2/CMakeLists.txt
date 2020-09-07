cmake_minimum_required(VERSION 3.5)

project(tutorial2)

set(CMAKE_DEBUG_POSTFIX "")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include_directories(../sample_nodes)

find_package(Boost COMPONENTS coroutine)
if(NOT ${Boost_FOUND})
    message(STATUS "Fetching Boost")
else()
    message(STATUS "Found Boost at ${Boost_DIR}")
endif()

find_package(BehaviorTreeV3)
if(NOT ${BehaviorTreeV3_FOUND})
    message(STATUS "Fetching BehaviorTreeV3")
else()
    message(STATUS "Found BehaviorTreeV3 at ${BehaviorTreeV3_DIR}")
endif()

add_executable(${PROJECT_NAME} main.cpp example_nodes.cpp movebase_node.cpp)
target_link_libraries(${PROJECT_NAME} BT::behaviortree_cpp_v3)
