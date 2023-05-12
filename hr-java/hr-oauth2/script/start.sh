#!bin/bash
app_name='hr-oauth2'
docker stop ${app_name}
echo '----stop container----'
docker rm ${app_name}
echo '----rm container----'
docker run -p 10400:10400 --name ${app_name} \
-v /etc/localtime:/etc/localtime \
-v /home/app/${app_name}/logs:/tmp/logs \
-e JAVA_OPTS="-Xms256m -Xmx256m" \
-e SPRING_ARGS="--spring.profiles.active=test --spring.cloud.nacos.discovery.ip=192.168.220.128" \
-d 01star/${app_name}:1.0.0-SNAPSHOT
echo '----start container----'
