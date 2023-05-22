#include "stdafx.h"
#include "PatentinfoController.h"

PatentinfoJsonVO::Wrapper PatentinfoController::execQueryPatentinfo(const PatentinfoQuery::Wrapper& query)
{
	// 创建响应对象
	auto vo = PatentinfoJsonVO::createShared();
	// 创建分页对象
	//auto pdto = PatentinfoPageDTO::createShared();
	//pdto->addData(PatentinfoDTO::createShared(/*oatpp::data::mapping::type::DTO::String(1), "专利1名称"*/));
	//pdto->addData(PatentinfoDTO::createShared(/*oatpp::data::mapping::type::DTO::String(2), "专利2名称"*/));
	//pdto->addData(PatentDTO::createShared(1, "zs"));
	//pdto->addData(PatentDTO::createShared(2, "ls"));
	// 响应结果
	vo->success({});
	return vo;
}





Uint64JsonVO::Wrapper PatentinfoController::execModifyPatentinfo(const PatentinfoDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}


