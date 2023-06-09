#include "stdafx.h"
#include "PimarmycadresService.h"
#include "dao/pimarmycadres/PimarmycadresDAO.h"
#include "domain/do/pimarmycadres/DelPimarmycadresDO.h"
#include "domain/do/pimarmycadres/AddPimarmycadresDO.h"
#include "ExcelComponent.h"
#include "CharsetConvertHepler.h"
#include "domain/do/pimarmycadres/PimarmycadresIntoDO.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"
#include "FastDfsClient.h"


uint64_t PimarmycadresService::saveManyData(const oatpp::String& fileBody, const oatpp::data::mapping::type::String& suffix, const oatpp::data::mapping::type::String& pimpersonid, const PayloadDTO& payload)
{
	// 根据时间戳生成一个临时文件名称
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
	ss << suffix.getValue("");

	// 临时文件名称
	std::string fileName = ss.str();
	// 保存文件到临时目录
	fileBody.saveToFile(fileName.c_str());

	// 上传到FastDFS文件服务器----------------------------------------//
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif
	std::string fieldName = client.uploadFile(fileName);
	//std::cout << "upload fieldname is : " << fieldName << std::endl;
	ss.str("");
	ss.clear();
	ss << "http://8.130.87.15:8888/" << fieldName;
	cout << ss.str() << endl;
	//上传完成----------------------------------------------------------//


	//从fastdfs下载文件--------------------------------------------------//
//#ifdef LINUX
//		// 下载链接前缀
//		std::string urlPrefix;
//	//定义客户端对象
//	// 定义一个Nacos客户端对象，用于获取配置
//	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
//	// 设置url前缀
//	auto thirdServerConfig = ns.getConfig("third-services.yaml");
//	urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";
//	// 从Nacos配置中心获取FastDFS客户端配置数据
//	std::string config = ns.getConfigText("client.conf");
//	// 定义客户端对象
//	FastDfsClient client(config, false);
//#else
////定义客户端对象
//	FastDfsClient client("80.130.87.15");
//#endif
	string name;
	if (!fileName.empty()){
		std::string path = "public/static/Excel/";
		name = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << name << std::endl;
	}
	//下载完成-------------------------------------------------------------//

	// 保存到文件
	ExcelComponent excel;

	std::string sheetName = CharsetConvertHepler::ansiToUtf8("军转干部表");
	// 从文件中读取
	auto readData = excel.readIntoVector(name, sheetName);

	PimarmycadresDAO dao;

	SnowFlake sf(1, 4);

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
		AddPimarmycadresDO data(row);
		//雪花算法生产id
		data.setpIMARMYCADRESID(to_string(sf.nextId()));

		data.setpIMID(pimpersonid);

		//更新时间
		//SimpleDateTimeFormat times;
		data.setuPDATEDATE(SimpleDateTimeFormat::format());
		data.setcREATEDATE(data.getcREATEMAN());
		// 从负载数据中获取创建人
		data.setcREATEMAN(payload.getUsername());
		data.setuPDATEMAN(payload.getUsername());

		//插入数据
		dao.insert(data);

	}

	return uint64_t(1);
}

PimarmycadresDTO::Wrapper PimarmycadresService::listDetail(const PimarmycadresQuery::Wrapper& query)
{
	// 构建返回对象
	//auto lists = MilitaryDTO::createShared();
	PimarmycadresDAO dao;
	auto lists = dao.selectDetail(query);
	auto dto = PimarmycadresDTO::createShared();
	if (!lists.empty()) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, lists.front(), pimid, pIMID, 
			form, fORM, 
			level, lEVEL, 
			occurtime, oCCURTIME, 
			annexPath, aNNEXPATH);
	}
	return dto;
}

bool PimarmycadresService::updateData(const PimarmycadresDTO::Wrapper& dto)
{
	// 组装DO数据
	PimarmycadresDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Pimid,pimid);
	// 执行数据修改
	PimarmycadresDAO dao;
	return dao.update(data) == 1;
}


PimarmycadresFindPageDTO::Wrapper PimarmycadresService::listAll(const PimarmycadresPageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PimarmycadresFindPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PimarmycadresDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PimarmycadresFindDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PimarmycadresFindDO sub : result)
	{
		auto dto = PimarmycadresFindDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, pimid, pIMID,
			form, fORM,
			level, lEVEL,
			occurtime,oCCURTIME,
			annexPath, aNNEXPATH);

		pages->addData(dto);
		dto.getPtr().get()->annexPath;
	}
	

	return pages;
}

uint64_t PimarmycadresService::saveData(const AddPimarmycadresDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	AddPimarmycadresDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, pIMID,pimid,
		fORM,form,
		lEVEL,level,
		oCCURTIME,occurtime,
		aNNEXPATH,annexPath,
		pIMARMYCADRESID,pimarmycadresid)
		// 执行数据添加
		PimarmycadresDAO dao;
	SnowFlake sf(1, 4);
	SimpleDateTimeFormat times;
	data.setpIMARMYCADRESID(to_string(sf.nextId()));

	data.setcREATEMAN(payload.getUsername());
	data.setuPDATEMAN(payload.getUsername());
	data.setcREATEDATE(times.format());
	data.setuPDATEDATE(times.format());

		
	return dao.insert(data);
}


bool PimarmycadresService::removeData(const DelPimarmycadresDTO::Wrapper& dto)
{
	PimarmycadresDAO dao;
	std::string pimpersonid = dto->pimid;
	for (auto it = dto->deleteById->begin(); it != dto->deleteById->end(); ++it)
	{
		dao.deleteById(pimpersonid, *it);
	}
	return true;
}


