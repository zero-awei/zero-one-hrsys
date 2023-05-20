#ifndef __CONTRACTPAGEVO__
#define __CONTRACTPAGEVO__

#include "../../GlobalInclude.h"
#include "../../dto/ContractDTO/ContractDTO_.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//合同信息JsonVo
class ContractJsonVO_ : public JsonVO<ContractDTO_::Wrapper>
{
	DTO_INIT(ContractJsonVO_, JsonVO<ContractDTO_::Wrapper>);
};

//路径JsonVo
class DownloadPathJsonVO_ : public JsonVO<DownloadPathDTO::Wrapper>
{
	DTO_INIT(DownloadPathJsonVO_, JsonVO<DownloadPathDTO::Wrapper>);

};



#include OATPP_CODEGEN_END(DTO)

#endif 