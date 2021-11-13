cmake_minimum_required(VERSION 3.20)
project(2D-pool)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp engine.cpp windowConfig.cpp)

include_directories(${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/include)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
