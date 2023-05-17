# fastdfs-spring-boot-starter

A high-performance fastdfs client compatible with  springboot 2. X. To avoid the confusion caused by manual introduction of jar package, provide common API, which is helpful for rapid development.

- Import dependence
- Initial configuration
- Connection pool
- More method
- Support multi tracker, multi storage, multi nginx load balancing mode
- Based on fastdfs client Java (1.29 snapshot) source code construction

Original author project address: https://github.com/bluemiaomiao/fastdfs-spring-boot-starter.git

# I. Quick start

## (1) Use Maven

```xml
<dependency>
    <groupId>io.github.bluemiaomiao</groupId>
    <artifactId>fastdfs-spring-boot-starter</artifactId>
    <version>2.0.1-RELEASE</version>
</dependency>
```

## (2) Use Gradle

```groovy
compile group: 'io.github.bluemiaomiao', name: 'fastdfs-spring-boot-starter', version: '2.0.0-RELEASE'
```

# II. Build from source

## (1) Download

```bash
git clone https://gitee.com/zero-awei/fastdfs-spring-boot-starter.git
cd fastdfs-spring-boot-starter
```

## (2) Install to local repository

```bash
mvn clean install
mvn source:jar install
mvn javadoc:jar install
```

## (3) Add to project

```xml
<dependency>
    <groupId>io.github.bluemiaomiao</groupId>
    <artifactId>fastdfs-spring-boot-starter</artifactId>
    <version>2.0.1-RELEASE</version>
</dependency>
```

## (4) Add annotations and service (``@EnableFastdfsClient``).

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

## (5) Add configuration entries(application.properties).

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

## (6) Add configuration entries(application.yml).

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

## (7) Enjoy it.

```java
@Autowired
private FastdfsClientService remoteService;

// Upload File
String[] remoteInfo;
try {
    remoteInfo = remoteService.autoUpload(image.getBytes(), type);
    log.info("File Server Group: " + remoteInfo[0]);
    log.info("File Server ID: " + remoteInfo[1]);
} catch (Exception e) {
    log.error("Upload file error: " + e.getMessage());
    return HttpStatus.INTERNAL_SERVER_ERROR;
}

// Download File
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
// If you use anti-hotlinking
FastdfsClientService.autoDownloadWithToken(String fileGroup, String remoteFileName, String clientIpAddress)
// If hotlinking is not used
FastdfsClientService.autoDownloadWithoutToken(String fileGroup, String remoteFileName, String clientIpAddress)
// upload file
FastdfsClientService.autoUpload(byte[] buffer, String ext)
```
