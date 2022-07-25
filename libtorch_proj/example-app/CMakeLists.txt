cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

if(UNIX AND NOT APPLE)
  set(LINUX TRUE)
endif()

if(JETSON)
 set(Torch_DIR /usr/local/lib/python3.6/dist-packages/torch/share/cmake/Torch)
endif()

project(example-app)

set(CMAKE_CXX_STANDARD 11)



find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(example-app example-app.cpp)

if (LINUX)
  message(STATUS ">>> Linux")
  target_link_libraries(example-app "-Wl,--no-as-needed" "${TORCH_LIBRARIES}")
else()
  target_link_libraries(example-app "${TORCH_LIBRARIES}")
endif (LINUX)

set_property(TARGET example-app PROPERTY CXX_STANDARD 14)

