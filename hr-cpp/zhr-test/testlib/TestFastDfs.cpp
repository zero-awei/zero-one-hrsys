#include "stdafx.h"
#include "TestFastDfs.h"
#include "FastDfsClient.h"
#include <iostream>

void TestFastDfs::testDfs()
{
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf");
#else
	//定义客户端对象
	FastDfsClient client("192.168.220.128");
#endif

	//测试上传
	std::string fileName = "../arch-demo/public/test.html";
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldName is : " << fieldName << std::endl;
	//测试下载
	if (!fieldName.empty())
	{
		std::string path = "./public/fastdfs";
		fieldName = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << fieldName << std::endl;
	}
	//测试删除文件
	/*if (!fieldName.empty())
	{
		std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
	}*/
}