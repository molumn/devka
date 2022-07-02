
project(devka-common)

add_subdirectory("3rdparty/spdlog")
link_libraries(spdlog)

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


add_library(${PROJECT_NAME} STATIC ${PROJECT_HPP_FILE} ${PROJECT_CPP_FILE})

preset_all_configuration(${PROJECT_NAME})

target_precompile_headers(devka-common PUBLIC src/devka-common/pch.hpp)
prepare_output_dir(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} INTERFACE 3rdparty/spdlog/include)
target_include_directories(${PROJECT_NAME} PUBLIC 3rdparty/spdlog/include)
target_include_directories(${PROJECT_NAME} INTERFACE src)
target_include_directories(${PROJECT_NAME} PUBLIC src)
