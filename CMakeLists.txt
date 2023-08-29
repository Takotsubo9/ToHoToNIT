cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Touhou-Koumatou CXX)

file(GLOB_RECURSE source src/*.cpp)

set(SDL2_INCLUDE_DIR CACHE PATH "SDL2 include directory")
set(SDL2_LIBRARY_DIR CACHE PATH "SDL2 library directory")

if(${ANDROID})

add_library(main SHARED ${source})

find_library(SDL2 SDL2)
find_library(SDL2_image SDL2_image)
find_library(SDL2_mixer SDL2_mixer)

target_link_libraries(main PRIVATE SDL2 SDL2_image SDL2_mixer)

else()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
file(COPY "${CMAKE_SOURCE_DIR}/bin" DESTINATION ${CMAKE_BINARY_DIR})
add_executable(${PROJECT_NAME} ${source})
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARY_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2_image SDL2_mixer)

endif()
