/**
 *  证书管理 —— 证书信息 —— 查询、更新指定证书 —— 楚孟献
 */
#include "stdafx.h"
#include "UpdateCertificateController.h"
#include "../../service/CertificateManage/SpercificCertificateService.h"

StringJsonVO::Wrapper UpdateCertificateController::execUpdateSpercificCertificate(const SpercificCertificateDTO::Wrapper& dto)
{
	{
		// 定义返回数据对象
		auto jvo = StringJsonVO::createShared();
		// 参数校验
		if (dto->PIMVOCATIONALID.getValue("").empty())
		{
			jvo->init(String("PIMVOCATIONALID must be not null"), RS_PARAMS_INVALID);
			return jvo;
		}
		// 定义一个Service
		SpercificCertificateService service;
		// 执行数据修
		if (service.updateData(dto)) {
			jvo->success(dto->PIMVOCATIONALID);
		}
		else
		{
			jvo->fail(dto->PIMVOCATIONALID);
		}
		// 响应结果
		return jvo;
	}
}

SpercificCertificateJsonVO::Wrapper UpdateCertificateController::execGetSpercificCertificate(const SpercificCertificateQuery::Wrapper& query)
{
	// 定义一个JsonVO对象
	auto vo = SpercificCertificateJsonVO::createShared();
	// 定义一个分页对象
	SpercificCertificateService service;
	auto result = service.querySpercificCertificate(query);

	vo->success(result);
	// 响应结果
	return vo;
}