# CMakeList.txt: lib-oatpp 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
add_definitions(-std=c++11)
# 包含库目录
include_directories ("./")
include_directories ("include")

# 编译动态库
file (GLOB_RECURSE SC_FILES src/*.cpp)
add_library (lib-oatpp STATIC ${SC_FILES})

# 静态库输出名修改
set_target_properties (lib-oatpp PROPERTIES OUTPUT_NAME oatpp-http)
# 防止同名库被删除
set_target_properties (lib-oatpp PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 安装库
install (TARGETS lib-oatpp ARCHIVE DESTINATION libstatic)
install (DIRECTORY include/ DESTINATION include/lib-oatpp)
