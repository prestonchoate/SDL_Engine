cmake_minimum_required (VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)

# Below line is for using C++14 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Our project name
project (sdl_engine)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory("src")

SET (LINK_LIBRARIES_NAMES framework)

# For finding our SDL2 package!
INCLUDE(FindPkgConfig)

# Searching SDL2 package.
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

# Including our external library's directory for header files!
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

list(APPEND LINK_LIBRARIES_NAMES ${SDL2_LIBRARIES})

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2IMAGE_INCLUDE_DIRS})

list (APPEND LINK_LIBRARIES_NAMES ${SDL2IMAGE_LIBRARIES})

# Linking SDL2 library with our project.
target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES_NAMES})

# Copy Assets directory to output
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/assets/** $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets)