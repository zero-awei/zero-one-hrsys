#include "stdafx.h"
#include <iostream>

#ifdef LINUX
#include "ServerInfo.h"
#include "NacosClient.h"
#include "YamlHelper.h"
#endif
#include "TerminationRemidnerFastdfs.h"
#include "FastDfsClient.h"

std::string TerminationFastDfs::downloadDfs(string fileName)
{
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf");
#else
	//定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif

	//测试上传
	std::string fieldName = client.uploadFile(fileName);
	//std::cout << "upload fieldname is : " << fieldName << std::endl;
	std::string url = "8.130.87.15:8888/" + fieldName;
	return url;
}

