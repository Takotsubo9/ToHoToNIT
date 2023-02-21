cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

project(Touhou-Koumatou CXX)
file(GLOB_RECURSE source src/*.cpp)
file(COPY "${CMAKE_SOURCE_DIR}/bin" DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${source})

set(SDL2_INCLUDE_DIR CACHE PATH "SDL2 include directory")
set(SDL2_LIBRARY_DIR CACHE PATH "SDL2 library directory")

target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2_image SDL2_mixer)
