#pragma once
#ifndef _JOBTITLE_INFORMATIONCONTROLLER_H_
#define _JOBTITLE_INFORMATIONCONTROLLER_H_
#include "stdafx.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/certificate-information/JobTitleInformationPageQuery.h"
#include "domain/dto/certificate-information/JobTitleInformationDTO.h"
#include "domain/vo/certificate-information/JobTitleInformationVO.h"
#include "oatpp/web/mime/multipart/InMemoryDataProvider.hpp"
#include "oatpp/web/mime/multipart/FileProvider.hpp"
#include "oatpp/web/mime/multipart/Reader.hpp"
#include "oatpp/web/mime/multipart/PartList.hpp"
using namespace oatpp;
namespace multipart = oatpp::web::mime::multipart;

// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class JobTitleInformationController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(JobTitleInformationController);
	// 定义接口
public:
	//定义查询接口描述
	ENDPOINT_INFO(queryJobTitleInformation) {
		// 定义接口标题,用到中英文字典函数，用过zh-dict.yaml确定参数
		info->summary = ZH_WORDS_GETTER("sample.get.summary");
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(JobTitleInformationPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他表单参数描述
		//传入职称名称 professoranalysis_name
		info->queryParams.add<String>("professoranalysis_name").description = ZH_WORDS_GETTER("sample.field.professoranalysis_name");
		//传入证书编号 credentials_num
		info->queryParams.add<String>("credentials_num").description = ZH_WORDS_GETTER("sample.field.credentials_num");
		//传入职称等级 professor_grades
		info->queryParams.add<String>("professor_grades").description = ZH_WORDS_GETTER("sample.field.professor_grades");
		//职称获取日期 zchqrq
		info->queryParams.add<String>("zchqrq").description = ZH_WORDS_GETTER("sample.field.zchqrq");
		//传入评审单位 reviewbody
		info->queryParams.add<String>("reviewbody").description = ZH_WORDS_GETTER("sample.field.reviewbody");
		//传入签发机构 lssuingagency
		info->queryParams.add<String>("lssuingagency").description = ZH_WORDS_GETTER("sample.field.lssuingagency");
		//传入职称聘用时间 employtime
		info->queryParams.add<String>("employtime").description = ZH_WORDS_GETTER("sample.field.employtime");
		//传入是否最高职称 enable
		info->queryParams.add<String>("enable").description = ZH_WORDS_GETTER("sample.field.enable");
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/certificate-information", queryJobTitleInformation, API_HANDLER_AUTH_PARAME, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(userQuery, JobTitleInformationQuery, queryParams);
		// 响应结果
		API_HANDLER_RESP_VO(execQueryJobTitleInformation(userQuery, authObject->getPayload()));
	}
private:
	// 3.3 演示分页查询数据
	JobTitleInformationPageJsonVO::Wrapper execQueryJobTitleInformation(const JobTitleInformationQuery::Wrapper& query, const PayloadDTO& payload);
};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DEBUG





