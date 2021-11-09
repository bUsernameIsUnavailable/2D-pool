cmake_minimum_required(VERSION 3.20)
project(2D-pool)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
link_directories(${OPENGL_LIBRARY_DIRS})
add_definitions(${OPENGL_DEFINITIONS})
list(APPEND OPENGL_LIBRARIES "glew32" "glew32s")
if (NOT OpenGL_FOUND)
    message(ERROR " OpenGL not found!")
endif(NOT OpenGL_FOUND)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if (NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

set(glm_DIR "glm/cmake/glm")
find_package(glm REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})
link_directories(${GLM_LIBRARY_DIRS})
add_definitions(${GLM_DEFINITIONS})
if (NOT glm_FOUND)
    message(ERROR " glm not found!")
endif(NOT glm_FOUND)

execute_process(
        COMMAND ${CMAKE_COMMAND} -E
        create_symlink ${CMAKE_CURRENT_SOURCE_DIR}/shaders ${CMAKE_CURRENT_BINARY_DIR}/shaders
)

add_subdirectory(src)
