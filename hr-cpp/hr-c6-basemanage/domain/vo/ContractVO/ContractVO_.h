#ifndef __CONTRACTPAGEVO__
#define __CONTRACTPAGEVO__

#include "../../GlobalInclude.h"
#include "../../dto/ContractDTO/ContractDTO_.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//��ͬ��ϢJsonVo
class ContractJsonVO_ : public JsonVO<ContractDTO_::Wrapper>
{
	DTO_INIT(ContractJsonVO_, JsonVO<ContractDTO_::Wrapper>);
};

//·��JsonVo
class DownloadPathJsonVO_ : public JsonVO<DownloadPathDTO::Wrapper>
{
	DTO_INIT(DownloadPathJsonVO_, JsonVO<DownloadPathDTO::Wrapper>);

};



#include OATPP_CODEGEN_END(DTO)

#endif 