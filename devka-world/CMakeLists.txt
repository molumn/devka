
project(devka-world
        VERSION 0.1.0.0
)

link_libraries(devka-common)
link_libraries(devka-graphics)
link_libraries(devka-physics)


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

prepare_output_dir(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE src)
target_include_directories(${PROJECT_NAME} PUBLIC src)

