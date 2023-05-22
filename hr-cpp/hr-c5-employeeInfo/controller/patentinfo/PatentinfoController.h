#pragma once

#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/query/patentinfo/PatentinfoQuery.h"
#include "domain/vo/patentinfo/PatentinfoVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) // 0

/**
 * 测试控制器
 */
class PatentinfoController : public oatpp::web::server::api::ApiController // 1
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PatentinfoController);
public: // 定义接口
	// 3 定义接口描述
	ENDPOINT_INFO(queryPatentinfo) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("patentInformation.select.summary");
		// 定义响应参数类型
		API_DEF_ADD_RSP_JSON_WRAPPER(PatentinfoPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 添加其他查询参数
		//info->queryParams.add<String>("ZLH").description = ZH_WORDS_GETTER("patentInformation.field.ZLH");
		//info->queryParams["ZLH"].addExample("default", String("patentInformation"));

		//员工姓名
		info->queryParams.add<String>("empname").description = ZH_WORDS_GETTER("patentInformation.person.empname");
		info->queryParams["empname"].addExample("default", String("LiHua"));
		//员工编号
		info->queryParams.add<String>("empID").description = ZH_WORDS_GETTER("patentInformation.person.empID");
		info->queryParams["empID"].addExample("default", String("1234"));
		//证件号码
		info->queryParams.add<String>("empidNumber").description = ZH_WORDS_GETTER("patentInformation.person.empidNumber");
		info->queryParams["empidNumber"].addExample("default", String("12345"));
		info->queryParams["empidNumber"].required = false;
		//组织
		info->queryParams.add<String>("emporg").description = ZH_WORDS_GETTER("patentInformation.person.emporg");
		info->queryParams["emporg"].addExample("default", String("HuaWeiZhongBu"));
		info->queryParams["emporg"].required = false;
		//部门
		info->queryParams.add<String>("empdep").description = ZH_WORDS_GETTER("patentInformation.person.empdep");
		info->queryParams["empdep"].addExample("default", String("Development department"));
		info->queryParams["empdepe"].required = false;
		//员工状态
		info->queryParams.add<String>("empstatus").description = ZH_WORDS_GETTER("patentInformation.person.empstatus");
		info->queryParams["empstatus"].addExample("default", String("working"));
		info->queryParams["empstatus"].required = false;
		//在岗状态
		info->queryParams.add<String>("emppostatus").description = ZH_WORDS_GETTER("patentInformation.person.emppostatus");
		info->queryParams["emppostatus"].addExample("default", String("yes"));
		info->queryParams["emppostatus"].required = false;











	}





	// 4 定义接口端点
	ENDPOINT(API_M_GET, "/test", queryPatentinfo, QUERIES(QueryParams, qps)) {
		// 解析查询参数（解析成领域模型对象）
		API_HANDLER_QUERY_PARAM(query, PatentinfoQuery, qps);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryPatentinfo(query));
	}

















	// 3.1 定义修改接口描述
	ENDPOINT_INFO(modifySample) {
		// 定义接口标题
		info->summary = ZH_WORDS_GETTER("patentInformation.put.summary");
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义修改接口处理
	ENDPOINT(API_M_PUT, "/employee-info/modify-patentinfo", modifySample, BODY_DTO(PatentinfoDTO::Wrapper, dto)) {
		// 响应结果
		API_HANDLER_RESP_VO(execModifyPatentinfo(dto));
	}












private: // 定义接口执行函数
	// 5 定义接口的执行函数
	PatentinfoPageJsonVO::Wrapper execQueryPatentinfo(const PatentinfoQuery::Wrapper& query);

	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyPatentinfo(const PatentinfoDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) // 0

#endif // !_TESTCONTROLLER_H_
