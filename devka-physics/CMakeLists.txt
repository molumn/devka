
project(${DEVKA_PHYSICS}
        VERSION 0.1.0.0
        LANGUAGES CXX
)

add_subdirectory("3rdparty/glm")
link_libraries("glm")

link_libraries(${DEVKA_COMMON})

file(GLOB DEVKA_PHYSICS_HPP_FILE
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_PHYSICS}/**.hpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_PHYSICS}/**/**.hpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_PHYSICS}/**/**/**.hpp"
)

file(GLOB DEVKA_PHYSICS_CPP_FILE
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_PHYSICS}/**.cpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_PHYSICS}/**/**.cpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_PHYSICS}/**/**/**.cpp"
)

add_library(${DEVKA_PHYSICS} SHARED ${DEVKA_PHYSICS_HPP_FILE} ${DEVKA_PHYSICS_CPP_FILE})
target_include_directories(${DEVKA_PHYSICS} PUBLIC "${PROJECT_SOURCE_DIR}/src")
shared_library_setting(${DEVKA_PHYSICS})
prepare_output_dir(${DEVKA_PHYSICS})
preset_all_configuration(${DEVKA_PHYSICS})
