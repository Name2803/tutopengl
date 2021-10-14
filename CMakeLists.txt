cmake_minimum_required(VERSION 3.13 FATAL_ERROR)


set(PROJECT_NAME Hi_core)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
	src/main.cpp
	render/render.h
	render/render.cpp
	mat/fs_shader001.txt
	mat/vs_shader001.txt
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)


add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)