#pragma once
#ifndef _ADDSCIRESULTDTO_H_
#define _ADDSCIRESULTDTO_H_
#define DTO_INIT_(type, field, name) DTO_FIELD(type, field); \
DTO_FIELD_INFO(field) { \
	info->description = ZH_WORDS_GETTER(name); \
}

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddSciResultDTO : public oatpp::DTO
{
	DTO_INIT(AddSciResultDTO, DTO);

	//更新人
	DTO_INIT_(String, UPDATEMAN, "sciresult.UPDATEMAN")

		//科研成果名称
		DTO_INIT_(String, PIMRESEARCHFINDINGSNAME, "sciresult.PIMRESEARCHFINDINGSNAME")
		//附件
		DTO_INIT_(String, FJ, "sciresult.FJ")

		//ENABLE
		DTO_INIT_(String, ENABLE, "sciresult.ENABLE")

		//建立时间
		DTO_INIT_(String, CREATEDATE, "sciresult.CREATEDATE")

		//更新时间
		DTO_INIT_(String, UPDATEDATE, "sciresult.UPDATEDATE")

		//建立人
		DTO_INIT_(String, CREATEMAN, "sciresult.CREATEMAN")

		//科研成果标识
		DTO_INIT_(String, PIMRESEARCHFINDINGSID, "sciresult.PIMRESEARCHFINDINGSID")
		//人员信息标识
		DTO_INIT_(String, PIMPERSONID, "sciresult.PIMPERSONID")
		//获取时间
		DTO_INIT_(String, HQSJ, "sciresult.HQSJ")
		//记录所属
		DTO_INIT_(String, JLSS, "sciresult.JLSS")
		//审批状态
		DTO_INIT_(String, JLSPZT, "sciresult.JLSPZT")
		//记录管理编号
		DTO_INIT_(String, JLGLBH, "sciresult.JLGLBH")
		//记录操作者
		DTO_INIT_(String, JLCZZ, "sciresult.JLCZZ")
		//拒绝原因
		DTO_INIT_(String, REASON, "sciresult.REASON")

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDWORKHISTORYDTO_H_