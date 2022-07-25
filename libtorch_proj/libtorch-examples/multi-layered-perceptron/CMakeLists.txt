cmake_minimum_required(VERSION 3.19)
project(multi-layered-perceptron)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_NAME multi-layered-perceptron)

add_executable(${EXECUTABLE_NAME} main.cpp include/mlp.hpp include/mlp_classifier.hpp)
target_include_directories(${EXECUTABLE_NAME} PRIVATE include)
if (LINUX)
  target_link_libraries(${EXECUTABLE_NAME} "-Wl,--no-as-needed" ${TORCH_LIBRARIES})
endif (LINUX)
target_link_libraries(${EXECUTABLE_NAME} ${TORCH_LIBRARIES})
