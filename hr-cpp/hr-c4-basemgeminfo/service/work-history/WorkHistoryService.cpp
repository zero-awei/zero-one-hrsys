#include "stdafx.h"
#include "WorkHistoryService.h"
#include "dao/work-history/WorkHistoryDAO.h"
#include "domain/do/work-history/DelWorkHistoryDO.h"
#include "domain/do/work-history/ModWorkHistoryDO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "domain/do/work-history/WorkHistoryIntoDO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

#ifdef LINUX
#include "../../ServerInfo.h"
#include "NacosClient.h"
#include "YamlHelper.h"
#endif

#include "FastDfsClient.h"

WorkHistoryDTO::Wrapper WorkHistoryService::listDetail(const WorkHistoryQuery::Wrapper& query)
{
	// 构建返回对象
	//auto lists = MilitaryDTO::createShared();
	WorkHistoryDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = WorkHistoryDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), rzkssj, Rzkssj, rzjssj, Rzjssj, ormorgname, Ormorgname, ormdutyname, Ormdutyname, ormpostname, Ormpostname, cfplx, Cfplx, experience, Experience, pimpersonid, Pimpersonid,updatedate, Updatedate, updateman, Updateman, pimworkhistoryid, Pimworkhistoryid);
	}
	return dto;
}

bool WorkHistoryService::updateData(const ModWorkHistoryDTO::Wrapper& dto)
{
	// 组装DO数据
	ModWorkHistoryDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Rzkssj, rzkssj, Rzjssj, rzjssj, Ormorgname, ormorgname, Ormdutyname, ormdutyname, Ormpostname, ormpostname, Cfplx, cfplx, Experience, experience, Updatedate,updatedate,Updateman,updateman,Pimworkhistoryid, pimworkhistoryid);
	// 执行数据修改
	WorkHistoryDAO dao;
	return dao.update(data);
}


WorkHistoryFindPageDTO::Wrapper WorkHistoryService::listAll(const WorkHistoryPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = WorkHistoryFindPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	WorkHistoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<WorkHistoryFindDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (WorkHistoryFindDO sub : result)
	{
		auto dto = WorkHistoryFindDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, rzkssj, rZKSSJ, 
			rzjssj, rZJSSJ, 
			ormorgname, oRMORGNAME, 
			ormorgsectorname, oRMORGSECTORNAME, 
			ormdutyname, oRMDUTYNAME, 
			ormpostname, oRMPOSTNAME, 
			cfplx, cFPLX, 
			experience, eXPERIENCE, 
			pimworkhistoryid, pIMWORKHISTORYID, 
			pimpersonid, pIMPERSONID);
		pages->addData(dto);

	}

	return pages;
}

uint64_t WorkHistoryService::saveData(const AddWorkHistoryDTO::Wrapper& dto, const PayloadDTO& payload)
{
	SnowFlake sf(1, 4);
	// 组装DO数据
	SimpleDateTimeFormat times;
	AddWorkHistoryDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, rZKSSJ, rzkssj, \
		rZJSSJ, rzjssj, oRMORGNAME, ormorgname, oRMORGSECTORNAME, \
		ormorgsectorname, oRMDUTYNAME, ormdutyname, oRMPOSTNAME, \
		ormpostname, cFPLX, cfplx, eXPERIENCE, experience, \
		pIMWORKHISTORYID, pimworkhistoryid, pIMPERSONID, pimpersonid);
		// 执行数据添加

	//雪花算法生产履历id
	data.setpIMWORKHISTORYID(to_string(sf.nextId()));

	data.setcREATEMAN(payload.getUsername());
	data.setuPDATEMAN(payload.getUsername());
	data.setcREATEDATE(times.format());
	data.setuPDATEDATE(times.format());


	WorkHistoryDAO dao;
	return dao.insert(data);
}

bool WorkHistoryService::removeData(const DelWorkHistoryDTO::Wrapper& dto)
{
	/*// 组装DO数据
	DelWorkHistoryDO data;


	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pIMPERSONID, pimpersonid);*/

	WorkHistoryDAO dao;
	std::string pimpersonid = dto->pimpersonid;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}

uint64_t WorkHistoryService::saveManyData(const std::string fileName, const String& pimpersonid, const String& createName)
{

	
#ifdef LINUX
	// 下载链接前缀
	std::string urlPrefix;
	//定义客户端对象
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
	//定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif
	string name;	
	if (!fileName.empty())
	{
		std::string path = "public/static/Excel/";
		name = client.downloadFile(fileName, &path);
		std::cout << "download savepath is : " << name << std::endl;
	}

	// 保存到文件
	ExcelComponent excel;

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("工作履历表");
	// 从文件中读取
	auto readData = excel.readIntoVector(name, sheetName);

	WorkHistoryDAO dao;
	
	SnowFlake sf(0, 31);

	bool tem = true;
	for (auto row : readData)
	{

		//判断文件中是否有数据
		for (size_t j = 0; j < row.size(); ++j)
		{
			if (row[j].empty())
			{
				return -1;
			}
			std::cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << "   ";
		}
		
		std::cout << endl;
		if (tem)
		{
			tem = false;
			continue;
		}
		AddWorkHistoryDO data(row);
		//雪花算法生产履历id
		data.setpIMWORKHISTORYID(to_string(sf.nextId()));

		//判断是谁的工作履历
		data.setpIMPERSONID(pimpersonid);

		//更新时间
		SimpleDateTimeFormat times;
		data.setcREATEDATE(times.format());
		data.setuPDATEDATE(times.format());
		data.setcREATEMAN(createName);
		data.setuPDATEMAN(createName);

		//插入数据
		dao.insert(data);

	}
	return uint64_t(1);
}

std::string WorkHistoryService::exportData(const WorkHistoryExportQuery::Wrapper& query)
{

	// 创建测试数据(实际是把数据库的数据放进来)


	WorkHistoryDAO dao;
	auto listData = dao.selectAllData(query);
	std::vector<std::vector<std::string>> datas;
	//构建表头
	std::vector<std::string> rowHead;
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("任职开始时间"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("任职结束时间"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("工作单位"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("部门"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("职务"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("岗位"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("兼职借调类型"));
	rowHead.push_back(CharsetConvertHepler::ansiToUtf8("是否主要经历"));
	datas.push_back(rowHead);


	//插入数据到Excel中
	for (auto row : listData)
	{
		std::vector<std::string> vecStr(row.WorkHistoryToVector());
		datas.push_back(vecStr);
	}

	std::stringstream ss;
	ss << "public/static/Excel/";

	// 计算时间戳
	auto now = std::chrono::system_clock::now();
	auto tm_t = std::chrono::system_clock::to_time_t(now);
	ss << std::put_time(std::localtime(&tm_t), "%Y%m%d%H%M%S");
	// 获取毫秒
	auto tSeconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
	auto tMilli = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
	auto ms = tMilli - tSeconds;
	ss << std::setfill('0') << std::setw(3) << ms.count();
	// 拼接后缀名
	ss << ".xlsx";

	std::string fileName = ss.str();
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要转换编码
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("工作履历表");

	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, datas);

	//测试是否有数据
	// 从文件中读取
	//auto readData = excel.readIntoVector(fileName, sheetName);
	//for (auto row : readData)
	//{
	//	//判断文件中是否有数据
	//	for (int j = 0; j < row.size(); ++j)
	//	{
	//		cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << "   ";
	//	}
	//	cout << endl;
	//}

	// 文件名称
	//std::string fileName = ss.str();
	// 保存文件到目录
	//String fileBody;
	//fileBody.saveToFile(fileName.c_str());


	std::string urlPrefix;
	// 上传到FastDFS文件服务器
#ifdef LINUX
	
	//定义客户端对象
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
	urlPrefix = "http://8.130.87.15:8888/";
	//定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << urlPrefix << fieldName;


	cout << ss.str() << endl;

	return ss.str();
}
