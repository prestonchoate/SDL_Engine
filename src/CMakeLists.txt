add_library(
    framework
    STATIC
    framework/framework.h
    framework/framework.cpp
    framework/gameObject.h
    framework/gameObject.cpp
    framework/gameManager.h
    framework/gameManager.cpp
)

target_include_directories(framework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/framework)