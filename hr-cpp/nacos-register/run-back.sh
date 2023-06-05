#!/bin/bash
#check parameters
if [ $# -eq 0 ]
then
  echo -e "\nThe startup parameters are incorrect. Refer to the following instructions\n"
  echo "Usage: $0 excuteabfile na=? ns=? fi=? [options]"
  echo "Options:"
  echo "na: nacos server host and port. example na=39.99.114.126:8848"
  echo "ns: nacos server namespace. example ns=1653f775-4782-46ad-9cd2-b60155a574c6"
  echo "sp: server port. example sp=8090"
  echo "fi: register server list filename. example fi=demo-nacos-cli.yaml"
  echo ""
  exit 1
fi
#add dynamic lib serach path
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`/../lib
#start server
nohup ./$* >logs.log 2>&1 &
