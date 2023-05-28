#include "stdafx.h"
#include "ContractInfoService.h"
#include "../../dao/ContractInfo/ContractInfoDAO.h"
#include "domain/dto/ContractDTO/ContractDTO_.h"
#include <stdlib.h>
#include "FastDfsClient.h"
ContractDTO_::Wrapper ContractInfoService::listContract(const ContractQuery_::Wrapper& query)
{
	// 构建返回对象
	auto res = ContractDTO_::createShared();
	//dao层逻辑运算
	ContractInfoDAO dao;
	list<ContractDO> result = dao.selectById(std::to_string(query->id.getValue(1)));
	// 将DO转换成DTO
	for (ContractDO sub : result)
	{
		auto dto = ContractDTO_::createShared();
		dto->id = sub.getId();
		dto->name = sub.getName();
		dto->type = sub.getType();
		dto->variety = sub.getVariety();
		dto->date = sub.getDate();
		dto->condition = sub.getCondition();
		dto->department_m = sub.getDepartment_m();
		dto->department_c = sub.getDepartment_c();
		dto->date_end = sub.getDate_end();
		dto->tip = sub.getTip();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, type, Type, variety, Variety, date, Date, condition, Condition, department_m, Department_m, department_c, Department_c, date_end, Date_end, tip, Tip);
		res = dto;
	}
	return res;
}

bool ContractInfoService::updateContract(const ContractDTO_::Wrapper& dto)
{
	//转个do
	ContractDO cdo;
	//cdo.setId(dto->id.getValue(1));
	//cdo.setName(dto->name.getValue("this is a name"));
	//cdo.setType(dto->type.getValue("..."));
	//cdo.setVariety(dto->variety.getValue("..."));
	//cdo.setDate(dto->date.getValue("2023-05-02 19:57:59"));
	//cdo.setCondition(dto->condition.getValue("..."));
	//cdo.setDepartment_m(dto->department_m.getValue("..."));
	//cdo.setDepartment_c(dto->department_c.getValue("..."));
	//cdo.setDate_end(dto->date_end.getValue("2023-05-02 19:57:59"));
	//cdo.setTip(dto->tip.getValue("..."));

	ZO_STAR_DOMAIN_DTO_TO_DO(cdo, dto, Name, name, Type, type, Variety, variety, Date, date, Condition, condition, Department_m, department_m, Department_c, department_c, Date_end, date_end, Tip, tip)
	//dao层逻辑运算
	ContractInfoDAO dao;
	return dao.update(cdo) == 1;
}


std::string ContractInfoService::downloadContract(const ContractDownloadQuery::Wrapper& query)
{
// TODO: 调用DAO查询数据条数

// TODO: 包装数据到Excel文件

// TODO: 上传到FastDFS文件服务器

// TODO: 生成下载链接并返回


	const String suffix = ".xls";
	// 根据时间戳生成一个临时文件名称
	std::stringstream ss;
	ss << "public/static/file/";
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


	//dao层逻辑运算
	ContractInfoDAO dao;
	auto res = dao.downloadByRows(query->sequence.getValue(""), query->rows.getValue(1));
	
	// 测试上传到FastDFS文件服务器
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf", 3);
#else
	//定义客户端对象
	FastDfsClient client("8.130.87.15");
#endif
	std::string fieldName = client.uploadFile(fileName);
	//std::cout << "upload fieldname is : " << res << std::endl;
	//ss.str("");
	//ss.clear();
	//ss << "8.130.87.15:8888/" << fieldName;

	return fieldName;
}