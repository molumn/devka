
project(editor
        VERSION 0.1.0.0
)

link_libraries(devka-world)
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

add_executable(${PROJECT_NAME} ${PROJECT_HPP_FILE} ${PROJECT_CPP_FILE})

prepare_output_dir(${PROJECT_NAME})

preset_all_configuration(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_HPP_FILE})
