cmake_minimum_required(VERSION 3.0)

if(UNIX AND NOT APPLE)
  set(LINUX TRUE)
endif()

project(linear-regression)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_NAME linear-regression)

add_executable(${EXECUTABLE_NAME} main.cpp include/linear_regression.hpp)
target_include_directories(${EXECUTABLE_NAME} PRIVATE include)

if (LINUX)
  target_link_libraries(${EXECUTABLE_NAME} "-Wl,--no-as-needed" ${TORCH_LIBRARIES})
else()
  target_link_libraries(${EXECUTABLE_NAME} ${TORCH_LIBRARIES})
endif (LINUX)