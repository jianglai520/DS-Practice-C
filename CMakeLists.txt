cmake_minimum_required(VERSION 3.20)
project(DS_Practice_C C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 递归收集源码目录下所有 .c 文件，为每个文件生成一个独立的可执行文件。
# 说明：
#   1. CONFIGURE_DEPENDS：新增 / 删除 .c 文件时自动重新生成构建系统（CMake >= 3.12）。
#   2. 必须排除构建目录（如 cmake-build-debug），否则会把 CMake 自己生成的
#      CMakeCCompilerId.c 也当成练习程序，多出一个 CMakeCCompilerId 可执行文件。
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.c")
list(FILTER SOURCES EXCLUDE REGEX "/cmake-build-")

foreach(SOURCE_FILE ${SOURCES})
    # 文件名（不含路径和扩展名）作为可执行目标名
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)
    # 所在目录名，用于分组显示和输出目录
    get_filename_component(DIR_NAME ${SOURCE_FILE} DIRECTORY)
    get_filename_component(DIR_NAME ${DIR_NAME} NAME)

    # 每个练习程序都有自己的 main，所以各自生成一个可执行文件
    add_executable(${EXE_NAME} ${SOURCE_FILE})

    # 输出到 bin/<目录名>/<文件名>.exe，方便区分各个练习程序
    set_target_properties(${EXE_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${DIR_NAME}"
    )

    # IDE 中按目录分组显示
    source_group("${DIR_NAME}" FILES ${SOURCE_FILE})
endforeach()
