/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/10 20:59:49

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
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
	//std::string fileName = "../arch-demo/public/test.html";
	//std::string fieldName = client.uploadFile(fileName);
	//std::cout << "upload fieldname is : " << fieldName << std::endl;
	////测试下载
	//if (!fieldName.empty())
	//{
	//	std::string path = "./public/fastdfs";
	//	fileName = client.downloadFile(fieldName, &path);
	//	std::cout << "download savepath is : " << fileName << std::endl;
	//}
	////测试删除文件
	//if (!fieldName.empty())
	//{
	//	std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
	//}

	std::string fieldName = "group1/M00/00/00/wKjcgGRbljCADaLTAAAWdeWd-tc02.html";
	std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
}
