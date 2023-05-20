#include "stdafx.h"
#include "TestFastDfs.h"
#include "FastDfsClient.h"
#include <iostream>

void TestFastDfs::testDfs()
{
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf");
#else
	//����ͻ��˶���
	FastDfsClient client("192.168.220.128");
#endif

	//�����ϴ�
	std::string fileName = "../arch-demo/public/test.html";
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldName is : " << fieldName << std::endl;
	//��������
	if (!fieldName.empty())
	{
		std::string path = "./public/fastdfs";
		fieldName = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << fieldName << std::endl;
	}
	//����ɾ���ļ�
	/*if (!fieldName.empty())
	{
		std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
	}*/
}