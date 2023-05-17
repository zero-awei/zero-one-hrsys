# fastdfs-spring-boot-starter

SpringBoot2.x的高性能FastDFS客户端。避免手动引入jar包导致项目混乱，提供常用的API，有助于快速上手开发。

- 自动添加依赖
- 初始化配置项
- 基于Commons Pool2 实现的高性能连接池
- 更多操作FastDFS的API
- 支持多Tracker多Storage多NGINX负载均衡模式
- 基于fastdfs-client-java(1.29-SNAPSHOT)源代码构建

原作者项目地址：https://github.com/bluemiaomiao/fastdfs-spring-boot-starter.git

# 一、快速开始

## （1）使用Maven

```xml
<dependency>
    <groupId>io.github.bluemiaomiao</groupId>
    <artifactId>fastdfs-spring-boot-starter</artifactId>
    <version>2.0.1-RELEASE</version>
</dependency>
```

## （2）使用Gradle

```groovy
compile group: 'io.github.bluemiaomiao', name: 'fastdfs-spring-boot-starter', version: '2.0.0-RELEASE'
```

# 二、手动编译 

## （1）克隆整个仓库

```bash
git clone https://gitee.com/zero-awei/fastdfs-spring-boot-starter.git
cd fastdfs-spring-boot-starter
```

## （2）安装到本地

```bash
mvn clean install
mvn source:jar install
mvn javadoc:jar install
```

## （3）添加到项目

```xml
<dependency>
    <groupId>io.github.bluemiaomiao</groupId>
    <artifactId>fastdfs-spring-boot-starter</artifactId>
    <version>2.0.1-RELEASE</version>
</dependency>
```

## （4） 在主配置类上添加注解 (``@EnableFastdfsClient``)

```java
@EnableFastdfsClient
@SpringBootApplication
public class DemoApplication {

    @Autowired
    private FastdfsClientService fastdfsClientService;

    public static void main(String[] args) {
        SpringApplication.run(DemoApplication.class, args);
    }
}
```
## （5） 添加配置条目(application.properties)

```properties
fastdfs.nginx-servers=192.168.80.2:8000,192.168.80.3:8000,192.168.80.4:8000
fastdfs.tracker-servers=192.168.80.2:22122,192.168.80.3:22122,192.168.80.4:22122
fastdfs.http-secret-key=your key
fastdfs.http-anti-steal-token=true
fastdfs.http-tracker-http-port=8080
fastdfs.network-timeout=30
fastdfs.connect-timeout=5
fastdfs.connection-pool-max-idle=18
fastdfs.connection-pool-min-idle=2
fastdfs.connection-pool-max-total=18
fastdfs.charset=UTF-8
```

## （6） 添加配置条目(application.yml)

```yaml
fastdfs:
  charset: UTF-8
  connect-timeout: 5
  http-secret-key: your key
  network-timeout: 30
  http-anti-steal-token: true
  http-tracker-http-port: 8080
  connection-pool-max-idle: 20
  connection-pool-max-total: 20
  connection-pool-min-idle: 2
  nginx-servers: 192.168.80.2:8000,192.168.80.3:8000,192.168.80.4:8000
  tracker-servers: 192.168.80.2:22122,192.168.80.3:22122,192.168.80.4:22122
```

## （7） 即刻享受它带来的便利

```java
@Autowired
private FastdfsClientService remoteService;

// 上传文件
String[] remoteInfo;
try {
    remoteInfo = remoteService.autoUpload(image.getBytes(), type);
    log.info("上传的服务器分组: " + remoteInfo[0]);
    log.info("上传的服务器ID: " + remoteInfo[1]);
} catch (Exception e) {
    log.error("Upload file error: " + e.getMessage());
    return HttpStatus.INTERNAL_SERVER_ERROR;
}

// 下载文件
String group = file.getGroup();
String storage = file.getStorageId();
String remoteFile = "Get file error.";

try {
    remoteFile = fastdfs.autoDownloadWithToken(group, storage, remoteAddress);
} catch (Exception e) {
    log.error("Get file error: " + e.getMessage());
}
```

```java
// 当启用防盗链机制时,需要使用该方法下载文件
FastdfsClientService.autoDownloadWithToken(String fileGroup, String remoteFileName, String clientIpAddress)
// 当没有启用防盗链机制时,需要使用该方法下载文件
FastdfsClientService.autoDownloadWithoutToken(String fileGroup, String remoteFileName, String clientIpAddress)
// 上传文件的方法
FastdfsClientService.autoUpload(byte[] buffer, String ext)
```
