cmake_minimum_required(VERSION 3.0)

project(Prototipo)

find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

add_executable(Prototipo main.cpp)
target_link_libraries(
  Prototipo
  ${CGAL_LIBRARIES}
   )