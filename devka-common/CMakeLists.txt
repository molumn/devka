
project(${DEVKA_COMMON}
        VERSION 0.1.0.0
        LANGUAGES CXX
)

add_subdirectory(3rdparty/spdlog)
link_libraries(spdlog)

file(GLOB DEVKA_COMMON_HPP_FILE
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_COMMON}/**.hpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_COMMON}/**/**.hpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_COMMON}/**/**/**.hpp"
)

file(GLOB DEVKA_COMMON_CPP_FILE
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_COMMON}/**.cpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_COMMON}/**/**.cpp"
        "${PROJECT_SOURCE_DIR}/src/${DEVKA_COMMON}/**/**/**.cpp"
)

add_library(${DEVKA_COMMON} STATIC ${DEVKA_COMMON_HPP_FILE} ${DEVKA_COMMON_CPP_FILE})
target_include_directories(${DEVKA_COMMON} PUBLIC "${PROJECT_SOURCE_DIR}/src")
shared_library_setting(${DEVKA_COMMON})
prepare_output_dir(${DEVKA_COMMON})
preset_all_configuration(${DEVKA_COMMON})
