# CMakeList.txt: nacos-client 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 设置文件名称
set (appName nacos-register)

# 包含库目录
include_directories ("./")
include_directories ("../lib-oatpp/include")
include_directories ("../lib-common/include")

# 链接库路径，程序运行的时候也在这里找
link_directories (${PROJECT_BINARY_DIR}/lib-oatpp)
link_directories (${PROJECT_BINARY_DIR}/lib-common)
link_directories (${PROJECT_SOURCE_DIR}/lib-oatpp/lib64)
link_directories (${PROJECT_SOURCE_DIR}/lib-common/lib64)
link_directories (${PROJECT_SOURCE_DIR}/lib-dy/lib64)

# 将源代码添加到此项目的可执行文件
file (GLOB_RECURSE SC_FILES ./*.cpp)

# 编译可执行文件
add_executable (${appName} ${SC_FILES})

# 链接库
target_link_libraries (${appName} "lib-common" "lib-oatpp")

# 链接其他库依赖库，如：你要链接libpthread直接写成pthread
target_link_libraries (${appName} pthread stdc++fs OpenSSL::SSL )
# 链接oatpp
target_link_libraries (${appName} oatpp-swagger oatpp )
# 链接ymal
target_link_libraries (${appName} yaml-cpp )
# 链接nacos
target_link_libraries (${appName} nacos-cli )

# 如果是Ubuntu系统,需要复制一下动态库
if(IS_UBUNTU)
	file (GLOB dylibdir "${PROJECT_SOURCE_DIR}/lib-dy/lib64/*")
    file (COPY ${dylibdir} DESTINATION "${PROJECT_BINARY_DIR}/${appName}")
endif()
# Swagger资源
file (GLOB swaggerRes "../lib-oatpp/include/oatpp-swagger/res/*")
file (COPY ${swaggerRes} DESTINATION ${PROJECT_BINARY_DIR}/${appName}/res)

# 安装文件
# 可执行文件
install (TARGETS ${appName} RUNTIME DESTINATION ${appName})
# Swagger资源
install (DIRECTORY "${PROJECT_SOURCE_DIR}/lib-oatpp/include/oatpp-swagger/res" DESTINATION ${appName})
# 第三方动态链接库
install (DIRECTORY "${PROJECT_SOURCE_DIR}/lib-dy/lib64/" DESTINATION lib FILES_MATCHING PATTERN "*.so*")
# 启动脚本
install (PROGRAMS ${PROJECT_SOURCE_DIR}/nacos-register/run-front.sh ${PROJECT_SOURCE_DIR}/nacos-register/run-back.sh DESTINATION ${appName})