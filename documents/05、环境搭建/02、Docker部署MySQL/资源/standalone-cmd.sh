mkdir /home/mysql
cd /home/mysql
docker run -id \
-p 3306:3306 \
--name mysql8 \
--restart always \
-v $PWD/conf:/etc/mysql/conf.d \
-v $PWD/log:/var/log/mysql \
-v $PWD/data:/var/lib/mysql \
-e MYSQL_ROOT_PASSWORD=123456 \
mysql:8.0.20 \
--lower_case_table_names=1