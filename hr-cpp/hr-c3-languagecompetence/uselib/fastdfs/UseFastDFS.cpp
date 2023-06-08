#include "stdafx.h"
#include "UseFastDFS.h"
#include <iostream>

#ifdef LINUX
#include "../../ServerInfo.h"
#include "NacosClient.h"
#include "YamlHelper.h"
#endif

#include "FastDfsClient.h"

/**
 * 实现调用FastDFS
 * 负责人：君
 */
std::string UseFastDFS::upload(std::string fileName)
{
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf");
#else
	//定义客户端对象
	FastDfsClient client(host);
#endif
	//上传
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	return url_prefix + fieldName;
}

std::string UseFastDFS::uploadWithNacos(std::string fileName)
{
	// 下载链接前缀
	std::string urlPrefix;
#ifdef LINUX
	// 定义一个Nacos客户端对象，用于获取配置
	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	// 设置url前缀
	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
	// 从Nacos配置中心获取FastDFS客户端配置数据
	std::string config = ns.getConfigText("client.conf");
	// 定义客户端对象
	FastDfsClient client(config, false);
#else
	// 设置url前缀
	urlPrefix = url_prefix;
	// 定义客户端对象
	FastDfsClient client(host);
#endif
	// 上传文件
	std::string fieldName = client.uploadFile(fileName);
	// 构建下载路径
	std::string downloadUrl = urlPrefix + fieldName;
	// 输出下载路径
	std::cout << "download url: " << downloadUrl << std::endl;
	return downloadUrl;
}