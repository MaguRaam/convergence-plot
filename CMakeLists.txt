cmake_minimum_required(VERSION 2.8.12)

SET(TARGET "convergence") 

project(${TARGET})

add_executable(${TARGET} ${TARGET}.cc)

find_package(PythonLibs 2.7)
target_include_directories(${TARGET} PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(${TARGET} ${PYTHON_LIBRARIES})