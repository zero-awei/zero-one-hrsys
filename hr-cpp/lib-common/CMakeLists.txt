# CMakeList.txt: lib-common 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)
add_definitions(-std=c++11)
# 包含库目录
include_directories ("./")
include_directories ("include")

# 编译动态库
file (GLOB_RECURSE SC_FILES src/*.cpp)

# 不编译Xlnt
if (USE_XLNT STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/ExcelComponent.cpp")
	message (STATUS "lib-common: not compile xlnt")
endif()
# 不编译FastDFS
if (USE_DFS STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/FastDfsClient.cpp")
	message (STATUS "lib-common: not compile fastdfs")
endif()
# 不编译Yaml
if (USE_YML STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/YamlHelper.cpp")
	message (STATUS "lib-common: not compile yamlcpp")
endif()
# 不编译Nacos
if (USE_NACOS STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/NacosClient.cpp")
	message (STATUS "lib-common: not compile nacos")
endif()
# 不编译RocketMQ
if (USE_ROCKETMQ STREQUAL OFF)
	list (REMOVE_ITEM SC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/RocketClient.cpp")
	message (STATUS "lib-common: not compile rocket client")
endif()

# 生成静态库
add_library (lib-common STATIC ${SC_FILES})

# 静态库输出名修改
set_target_properties (lib-common PROPERTIES OUTPUT_NAME common)
# 防止同名库被删除
set_target_properties (lib-common PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 安装库
install (TARGETS lib-common ARCHIVE DESTINATION libstatic)
install (DIRECTORY include/ DESTINATION include/lib-common)
