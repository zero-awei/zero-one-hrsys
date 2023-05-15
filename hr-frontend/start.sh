#!bin/bash
nginx_dir='/home/nginx/html'
docker stop nginx
echo '----stop nginx----'
rm -rf ${nginx_dir}
echo '----rm html dir----'
mv dist ${nginx_dir}
echo '----mv dist dir to html dir----'
docker start nginx
echo '----start nginx----'