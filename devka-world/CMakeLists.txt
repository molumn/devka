
project(${DEVKA_WORLD}
        VERSION 0.1.0.0
        LANGUAGES CXX
)

link_libraries(${DEVKA_COMMON})
link_libraries(${DEVKA_PHYSICS})
link_libraries(${DEVKA_GRAPHICS})

file(GLOB DEVKA_WORLD_HPP_FILE
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_WORLD}/**.hpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_WORLD}/**/**.hpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_WORLD}/**/**/**.hpp"
)

file(GLOB DEVKA_WORLD_CPP_FILE
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_WORLD}/**.cpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_WORLD}/**/**.cpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_WORLD}/**/**/**.cpp"
)

add_library(${DEVKA_WORLD} SHARED ${DEVKA_WORLD_HPP_FILE} ${DEVKA_WORLD_CPP_FILE})
target_include_directories(${DEVKA_WORLD} PUBLIC "${PROJECT_SOURCE_DIR}/src")
shared_library_setting(${DEVKA_WORLD})
prepare_output_dir(${DEVKA_WORLD})
preset_all_configuration(${DEVKA_WORLD})
