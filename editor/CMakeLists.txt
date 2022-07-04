
project(${DEVKA_EDITOR}
        VERSION 0.1.0.0
        LANGUAGES CXX
)

link_libraries(${DEVKA_WORLD})
link_libraries(${DEVKA_COMMON})     # test

file(GLOB DEVKA_EDITOR_HPP_FILE
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_EDITOR}/**.hpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_EDITOR}/**/**.hpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_EDITOR}/**/**/**.hpp"
)

file(GLOB DEVKA_EDITOR_CPP_FILE
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_EDITOR}/**.cpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_EDITOR}/**/**.cpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_EDITOR}/**/**/**.cpp"
)

add_executable(${DEVKA_EDITOR} ${DEVKA_EDITOR_HPP_FILE} ${DEVKA_EDITOR_CPP_FILE})
target_include_directories(${DEVKA_EDITOR} PUBLIC "${PROJECT_SOURCE_DIR}/src")
prepare_output_dir(${DEVKA_EDITOR})
preset_all_configuration(${DEVKA_EDITOR})
