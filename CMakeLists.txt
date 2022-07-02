CMAKE_MINIMUM_REQUIRED(VERSION 3.22.0)

SET(CMAKE_CXX_STANDARD 23)

CMAKE_PATH(SET SOLUTION_OUTPUT_PRE_DIR "~/solutions/Engine/devka") # your project directory (local git repository path)

macro(prepare_output_dir target_name)
    set_target_properties(${target_name}
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${SOLUTION_OUTPUT_PRE_DIR}/.out/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_NAME}/${target_name}-lib"
            LIBRARY_OUTPUT_DIRECTORY "${SOLUTION_OUTPUT_PRE_DIR}/.out/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_NAME}/${target_name}-lib"
            RUNTIME_OUTPUT_DIRECTORY "${SOLUTION_OUTPUT_PRE_DIR}/.out/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_HOST_SYSTEM_NAME}/${target_name}-bin"
    )
endmacro()

macro(shared_library_setting target_name)
    target_compile_definitions(${target_name} PRIVATE DK_DLL)
endmacro()

macro(preset_all_configuration target_name)
    if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
        target_compile_definitions(${target_name} PRIVATE DK_DEBUG)
    elseif(${CMAKE_BUILD_TYPE} STREQUAL Release)
        target_compile_definitions(${target_name} PRIVATE DK_RELEASE)
    endif()

    if (${CMAKE_SYSTEM_NAME} STREQUAL Linux)
        target_compile_definitions(${target_name} PRIVATE DK_PLATFORM_LINUX)
    elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
        target_compile_definitions(${target_name} PRIVATE DK_PLATFORM_WINDOWS)
    endif ()

    target_compile_options(${target_name} PUBLIC -fms-extensions)
endmacro()


project(devka
        VERSION 0.1.0
)

add_subdirectory(devka-common)
add_subdirectory(devka-graphics)
add_subdirectory(devka-physics)
add_subdirectory(devka-world)
add_subdirectory(editor)
