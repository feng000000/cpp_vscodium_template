# -------- base settings --------
# 生成 compile_commands.json 供 clangd 读取
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 指定 cmake 最低版本
cmake_minimum_required(VERSION 3.22.1)

# 指定项目名称和语言
project(cpp_template CXX)

# DEBUG:
message("build project: " ${CMAKE_CURRENT_SOURCE_DIR})
message("CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
message("CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR})


# -------- 全局头文件 library --------
add_library(global_headers INTERFACE)
target_include_directories(global_headers INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
# -------- core library --------
# 添加 core 库
add_library(core
    "src/core/core.cpp"
    # TODO: ...
)
# 链接全局头文件
target_link_libraries(core PUBLIC global_headers)


# ---------- executable ----------
# 生成可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 设置 c++ 版本
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

# 链接全局头文件
target_link_libraries(${PROJECT_NAME} PRIVATE global_headers)
# 链接 core 库
target_link_libraries(${PROJECT_NAME} PRIVATE core)