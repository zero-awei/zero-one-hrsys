#include "stdafx.h"
#include "CertificateController.h"
#include"../../service/Certificate/CertificateService.h"

// 分页查询数据
CertificatePageJsonVO::Wrapper CertificateController::execQueryCertificate(const CertificateQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	CertificateService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CertificatePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

// 新增数据
Uint64JsonVO::Wrapper CertificateController::execAddCertificate(const CertificateDTO::Wrapper& dto)
{

	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->seialno || !dto->pimqualtypename)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// 有效值校验
	if (dto->seialno < 0 || dto->pimqualtypename->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CertificateService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	jvo->success(UInt64(id));

	return jvo;
}
// 修改数据
Uint64JsonVO::Wrapper CertificateController::execModifyCertificate(const CertificateDTO::Wrapper& dto)
{
	// 定义返回数据对象

	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->seialno || dto->seialno <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	CertificateService service;
	service.updateData(dto);
	jvo->success(dto->seialno);
	return jvo;
}

// 删除数据
Uint64JsonVO::Wrapper CertificateController::execRemoveCertificate(const CertificateDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->seialno || dto->seialno <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CertificateService service;
	// 执行数据删除
	service.removeData(dto->seialno.getValue(0));
	jvo->success(dto->seialno);

	// 响应结果
	return jvo;
}
