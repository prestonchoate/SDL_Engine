add_library(
    framework
    STATIC
    framework/framework.h
    framework/framework.cpp
    framework/player.h
    framework/player.cpp
)

target_include_directories(framework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/framework)