cmake_minimum_required(VERSION 3.20)
project(DS_Practice_C)

set(CMAKE_C_STANDARD 11)

# 遍历所有子目录，为每个.c文件生成独立的可执行文件
file(GLOB_RECURSE SOURCES "*.c")

foreach(SOURCE_FILE ${SOURCES})
    # 获取文件名（不含路径和扩展名）
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)
    # 获取所在目录名（用于分组显示）
    get_filename_component(DIR_NAME ${SOURCE_FILE} DIRECTORY)
    get_filename_component(DIR_NAME ${DIR_NAME} NAME)

    # 创建可执行文件
    add_executable(${EXE_NAME} ${SOURCE_FILE})

    # 设置输出目录（可选，方便管理）
    set_target_properties(${EXE_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${DIR_NAME}"
    )

    # 分组显示（在IDE中按目录分组）
    source_group("${DIR_NAME}" FILES ${SOURCE_FILE})
endforeach()
