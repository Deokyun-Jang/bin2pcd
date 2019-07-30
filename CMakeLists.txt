cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
add_compile_options(-std=c++11)

project(bin_to_pcd)

find_package(PCL 1.7 REQUIRED COMPONENTS common io)

include_directories(${PCL_INCLUDE_DIRS})

link_directories(${PCL_LIBRARY_DIRS})

add_definitions(${PCL_DEFINITIONS})
add_executable(bin_to_pcd bin2pcd.cpp)
target_link_libraries(bin_to_pcd ${PCL_LIBRARIES})
