#该镜像需要依赖的基础镜像
FROM openjdk:8
# 指定维护者的名字
MAINTAINER 01star
# 将当前target目录下的jar包复制到docker容器中
ADD target/hr-j1-sysmanager-1.0.0-SNAPSHOT.jar app.jar
# 定义JVM参数
ENV JAVA_OPTS="-Xms256m -Xmx256m"
ENV SPRING_ARGS=""
RUN echo "JAVA_OPTS=" $JAVA_OPTS
# 设置容器启动执行指令
CMD java $JAVA_OPTS -jar app.jar --logging.file.path=/tmp/logs/spring-boot $SPRING_ARGS