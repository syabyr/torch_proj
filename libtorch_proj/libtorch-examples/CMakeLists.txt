cmake_minimum_required(VERSION 3.0)
project(libtorch-examples)

option(INSTALL_TORCH "Automatically download and install libtorch." ON)
option(CUDA "Download GPU Version" ON)
option(INSTALL_PYTHON_DEPENDENCIES "Install Python Dependencies during build" ON)
option(DOWNLOAD_MNIST "Download the MNIST Dataset during build" ON)



set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_NAME main)
#set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/libtorch)

include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/include)

if(JETSON)
 set(Torch_DIR /usr/local/lib/python3.6/dist-packages/torch/share/cmake/Torch)
endif()

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(${EXECUTABLE_NAME} main.cpp)
target_link_libraries(${EXECUTABLE_NAME} "${TORCH_LIBRARIES}")

set(DATA_DIR ${CMAKE_SOURCE_DIR}/data CACHE PATH "Dataset download directory")
file(MAKE_DIRECTORY ${DATA_DIR})



# Linear Regression
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/linear-regression)
add_custom_target(linear_regression)
add_dependencies(linear_regression linear-regression)

# Logistic Regression
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/logistic-regression)
add_custom_target(logistic_regression)
add_dependencies(logistic_regression logistic-regression)

# Multi-Layered Perceptron
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/multi-layered-perceptron)
add_custom_target(mlp_example)
add_dependencies(mlp_example multi-layered-perceptron)

# Convnet-Classification
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/convnet)
add_custom_target(convnet_example)
add_dependencies(convnet_example convnet)
