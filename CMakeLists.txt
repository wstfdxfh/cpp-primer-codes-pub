cmake_minimum_required(VERSION 3.10)
project(MultiMainProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 获取当前目录下的所有 .cpp 文件
file(GLOB ROOT_CPP_FILES "${CMAKE_SOURCE_DIR}/*.cpp")

# 为每个 .cpp 文件创建一个可执行文件
foreach(CPP_FILE ${ROOT_CPP_FILES})
    get_filename_component(EXE_NAME ${CPP_FILE} NAME_WE)
    add_executable(${EXE_NAME} ${CPP_FILE})
endforeach()

# 遍历所有子目录
file(GLOB SUBDIRS RELATIVE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/*)
foreach(SUBDIR ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${SUBDIR})
        # 获取子目录中的所有 .cpp 文件
        file(GLOB SUBDIR_CPP_FILES "${CMAKE_SOURCE_DIR}/${SUBDIR}/*.cpp")
        foreach(CPP_FILE ${SUBDIR_CPP_FILES})
            get_filename_component(EXE_NAME ${CPP_FILE} NAME_WE)
            add_executable(${EXE_NAME} ${CPP_FILE})
        endforeach()
    endif()
endforeach()
