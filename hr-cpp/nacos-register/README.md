# `Nacos`批量注册服务

## 简介
用于实现`Nacos`批量服务注册以及解决在单个物理机上面无法同时启动多个`NamingServer`导致无法多个服务注册的问题，使用它实现在当个物理机上面的统一注册效果。

## 目录结构说明
> `nacos-register`
>
> > `CMakeLists.txt` -- `Cmake`跨平台编译配置文件
> >
> > `SystemInterceptor.cpp` -- 系统拦截器实现
> >
> > `Macros.h` -- 通用宏定义
> >
> > `ServerInfo.h` -- 服务器信息缓存单例
> >
> > `main.cpp` -- 程序入口
> >
> > `run-xxxx.sh` -- 服务启动脚本
> >
> > `README.md` -- 模块自述文件

## 启动参数说明

注册服务启动参数说明

```sql
"sp: 本服务器启动使用的端口。 比如 sp=8070"
"na: Nacos 服务器的ip和端口。 比如 na=39.99.114.126:8848"
"ns: Nacos 服务器的命名空间。 比如 ns=1653f775-4782-46ad-9cd2-b60155a574c6"
"fi: 要注册的服务列表配置文件名称。比如 fi=demo-nacos-cli.yaml"
```

## 注册服务列配置示例

要完成注册需要再`Nacos`配置中心添加对应的配置文件，每个配置文件的格式如下：

```yaml
---
- ip: 192.168.220.128
  port: 8090 
  name: feign-cpp-demo1
- ip: 192.168.220.128 
  port: 8091
  name: feign-cpp-demo2
```

配置完成后不要忘记通过启动参数的方式将配置文件名称告诉给注册服务

