
project(glad)

add_library(${PROJECT_NAME} STATIC
        "include/glad/glad.h"
        "include/KHR/khrplatform.h"
        "src/glad.c"
)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")
