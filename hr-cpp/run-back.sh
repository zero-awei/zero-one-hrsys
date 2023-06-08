#!/bin/bash
#check parameters
if [ $# -eq 0 ]
then
  echo -e "\nThe startup parameters are incorrect. Refer to the following instructions\n"
  echo "Usage: $0 excuteabfile na=? ns=? ip=? sn=? [options]"
  echo "Options:"
  echo "na: nacos server host and port. example na=39.99.114.126:8848"
  echo "ns: nacos server namespace. example ns=1653f775-4782-46ad-9cd2-b60155a574c6"
  echo "ip: register ip. example ip=192.168.220.128"
  echo "sn: register service name. example sn=feign-cpp-sample"
  echo "sp: server port. example sp=8090"
  echo "du: mysql database username. example du=root"
  echo "dp: mysql database password. example dp=123456"
  echo "dn: mysql database dbname. example dn=test"
  echo "dh: mysql database host. example dh=192.168.220.128"
  echo "dP: mysql database port. example dP=3306"
  echo "dm: mysql database pool maxsize. example dm=25"
  echo ""
  exit 1
fi
#add dynamic lib serach path
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`/../lib
#start server
nohup ./$* >logs.log 2>&1 &
