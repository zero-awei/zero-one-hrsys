#include "stdafx.h"
#include "LegalEntityMaiService.h"
#include "dao/LegalEntityMai/LegalEntityMaiDAO.h"
#include "CharsetConvertHepler.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "SnowFlake.h"
#include "SimpleDateTimeFormat.h"

/* 法人主体维护Service层具体实现--（组织管理-数据设置-法人主体维护）--TripleGold */
LegalEntityMaiPageDTO::Wrapper LegalEntityMaiService::listAll(const LegalEntityMaiQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = LegalEntityMaiPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	LegalEntityMaiDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<OrmsignorgDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (OrmsignorgDO sub : result)
	{
		auto dto = LegalEntityMaiDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ORMSIGNORGID, Id, ORMSIGNORGNAME, Name,ORGCODE, Code);
		/*ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ORMSIGNORGID, ORMSIGNORGID,
			UPDATEMAN, UPDATEMAN, CREATEMAN, CREATEMAN,
			CREATEDATE, CREATEDATE, ORMSIGNORGNAME, ORMSIGNORGNAME,
			UPDATEDATE, UPDATEDATE, ORGCODE, ORGCODE, ZZJC, ZZJC);*/
		pages->addData(dto);
	}
	return pages;
}

bool LegalEntityMaiService::updateData(const LegalEntityMaiDTO::Wrapper& dto)
{
	// 组装DO数据
	OrmsignorgDO data;
	/*data.setId(dto->ORMSIGNORGID.getValue(""));
	data.setName(dto->ORMSIGNORGNAME.getValue(""));
	data.setCode(dto->ORGCODE.getValue(""));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, ORMSIGNORGID, Name, ORMSIGNORGNAME, Code, ORGCODE);
	// 执行数据添加
	LegalEntityMaiDAO dao;
	return dao.update(data) == 1;
}

uint64_t LegalEntityMaiService::saveData(const LegalEntityMaiAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	OrmsignorgDO data;
	/*data.setName(dto->ORMSIGNORGNAME.getValue(""));
	data.setCode(dto->ORGCODE.getValue(""));*/
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, ORMSIGNORGNAME, Code, ORGCODE);
	
	// 雪花算法生成唯一标识ID
	SnowFlake f2(1, 2);
	data.setId(to_string(f2.nextId()));
	// 更新时间
	SimpleDateTimeFormat time;
	data.setCreateman(payload.getUsername());
	data.setCreateDate(time.format());
	data.setUpdateman(payload.getUsername());
	data.setUpdatedate(time.format());

	// 执行数据添加
	LegalEntityMaiDAO dao;
	return dao.insert(data);
}

uint64_t LegalEntityMaiService::savaBatchDataWithFile(const std::string fileName, const PayloadDTO& payload)
{
	// 保存到文件
	ExcelComponent excel;
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("法人主体表");
	// 从文件中读取
	auto readData = excel.readIntoVector(fileName, sheetName);

	LegalEntityMaiDAO dao;

	SnowFlake f2(1, 2);

	bool temp = true;	// 防止把表头也加入数据库
	for (auto row : readData)
	{
		// 判断文件中是否有数据
		for (size_t j = 0; j < row.size(); ++j)
		{
			if (row[j].empty()) return -1;
			std::cout << CharsetConvertHepler::utf8ToAnsi(row[j]) << " ";
		}

		std::cout << std::endl;
		if (temp) {
			temp = false;
			continue;
		}
		OrmsignorgDO data(row);
		// 雪花算法生成唯一标识ID
		data.setId(to_string(f2.nextId()));
		// 更新时间
		SimpleDateTimeFormat time;
		data.setCreateman(payload.getUsername());
		data.setCreateDate(time.format());
		data.setUpdateman(payload.getUsername());
		data.setUpdatedate(time.format());

		// 插入数据
		if (!dao.insert(data)) return -1;
	}
	return 1;
}

bool LegalEntityMaiService::deleteById(const LegalEntityMaiDelDTO::Wrapper& dto)
{
	LegalEntityMaiDAO dao;
	// 迭代器循环删除数据
	for (auto it = dto->Ids->begin(); it != dto->Ids->end(); it++) {
		dao.deleteById(*it);
	}
	return true;
}

std::string LegalEntityMaiService::exportFile(const LegalEntityMaiQuery::Wrapper& query)
{
	// 创建导出数据
	LegalEntityMaiDAO dao;
	// 设置最大查询数据条数
	uint64_t cnt = dao.count(query);
	if (cnt > 5000) {
		query->pageSize = 5000;
	}
	else {
		query->pageSize = cnt;
	}
	// 得到查询结果
	list<OrmsignorgDO> res = dao.selectWithPage(query);
	
	
	std::vector<std::vector<std::string>> data;
	// 构建Excel表头
	std::vector<std::string> row;
	row.push_back(CharsetConvertHepler::ansiToUtf8("法人主体组织"));
	row.push_back(CharsetConvertHepler::ansiToUtf8("组织编号"));
	data.push_back(row);
	// 根据查询结果构建Excel数据
	for (auto info : res)
	{
		row.clear();
		row.push_back(info.getName());
		row.push_back(info.getCode());
		data.push_back(row);
	}

	// 定义保存数据位置和页签名称
	std::string fileName = "./public/excel/LegalEntityMai.xlsx";
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要转换编码
	std::string sheetName = CharsetConvertHepler::ansiToUtf8("法人主体表");

	// 保存到文件
	ExcelComponent excel;
	excel.writeVectorToFile(fileName, sheetName, data);
	// 从文件中读取
	auto readData = excel.readIntoVector(fileName, sheetName);
	for (auto row : readData)
	{
		for (auto cellVal : row)
		{
			// 注意：这里使用了编码转换，目的是为了在控制台打印显示不乱码，如果是将数据写入数据库，那么就不需要再进行编码转换了
			cout << CharsetConvertHepler::utf8ToAnsi(cellVal) << ",";
		}
		cout << endl;
	}

	// 上传文件至FastDfs
#ifdef LINUX
//定义客户端对象
	FastDfsClient client("conf/client.conf");
#else
	//定义客户端对象
	FastDfsClient client("192.168.241.128");
#endif
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldName is: " << fieldName << std::endl;
	remove(fileName.c_str());
	// 构建下载路径
	std::string url;
	url = "http://192.168.241.128:8888/" + fieldName;
	return url;
}

