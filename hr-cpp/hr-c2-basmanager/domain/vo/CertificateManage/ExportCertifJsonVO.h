#pragma once
/*
（证书管理-证书信息-导出证书（导出本页在前端完成））--洛洛
*/
#ifndef _EXPORTCERTIF_VO_
#define _EXPORTCERTIF_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/ExportCertifDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class ExportCertifJsonVO : public JsonVO<ExportCertifDTO::Wrapper> {
	DTO_INIT(ExportCertifJsonVO, JsonVO<ExportCertifDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ExportCertifPageJsonVO : public JsonVO<ExportCertifPageDTO::Wrapper> {
	DTO_INIT(ExportCertifPageJsonVO, JsonVO<ExportCertifPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORTCERTIF_VO_