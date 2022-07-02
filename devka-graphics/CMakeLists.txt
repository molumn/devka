

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


project(devka-graphics)

add_subdirectory(3rdparty/glfw)

find_package(OpenGL REQUIRED)
link_libraries(glfw)
link_libraries(OpenGL::GL)

link_libraries(devka-common)

file(GLOB PROJECT_HPP_FILE
        "src/${PROJECT_NAME}/**.hpp"
        "src/${PROJECT_NAME}/**/**.hpp"
        "src/${PROJECT_NAME}/**/**/**.hpp"
        )

file(GLOB PROJECT_CPP_FILE
        "src/${PROJECT_NAME}/**.cpp"
        "src/${PROJECT_NAME}/**/**.cpp"
        "src/${PROJECT_NAME}/**/**/**.cpp"
        )

add_library(${PROJECT_NAME} SHARED ${PROJECT_HPP_FILE} ${PROJECT_CPP_FILE})

preset_all_configuration(${PROJECT_NAME})

shared_library_setting(${PROJECT_NAME})
prepare_output_dir(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PRIVATE 3rdparty/glfw/include)
target_include_directories(${PROJECT_NAME} INTERFACE src)
target_include_directories(${PROJECT_NAME} PUBLIC src)
