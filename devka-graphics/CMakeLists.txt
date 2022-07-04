

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


project(${DEVKA_GRAPHICS}
        VERSION 0.1.0.0
        LANGUAGES CXX
)

add_subdirectory(3rdparty/glfw)
add_subdirectory(3rdparty/glad)
link_libraries(glad)

link_libraries(${DEVKA_COMMON})

find_package(OpenGL REQUIRED)
link_libraries(glfw)
link_libraries(OpenGL::GL)

file(GLOB DEVKA_GRAPHICS_HPP_FILE
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_GRAPHICS}/**.hpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_GRAPHICS}/**/**.hpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_GRAPHICS}/**/**/**.hpp"
)

file(GLOB DEVKA_GRAPHICS_CPP_FILE
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_GRAPHICS}/**.cpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_GRAPHICS}/**/**.cpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_GRAPHICS}/**/**/**.cpp"
)

add_library(${DEVKA_GRAPHICS} STATIC ${DEVKA_GRAPHICS_HPP_FILE} ${DEVKA_GRAPHICS_CPP_FILE})
target_include_directories(${DEVKA_GRAPHICS} PUBLIC "${PROJECT_SOURCE_DIR}/3rdparty/glad/include")
target_include_directories(${DEVKA_GRAPHICS} PUBLIC "${PROJECT_SOURCE_DIR}/src")
shared_library_setting(${DEVKA_GRAPHICS})
prepare_output_dir(${DEVKA_GRAPHICS})
preset_all_configuration(${DEVKA_GRAPHICS})

