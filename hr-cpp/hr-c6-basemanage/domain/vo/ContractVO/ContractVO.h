#ifndef __CONTRACTPAGEVO__
#define __CONTRACTPAGEVO__

#include "../../GlobalInclude.h"
#include "../../dto/ContractDTO/ContractDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//合同信息JsonVo
class ContractJsonVO : public JsonVO<ContractDTO::Wrapper>
{
	DTO_INIT(ContractJsonVO, JsonVO<ContractDTO::Wrapper>);
};

//合同下载路径JsonVo
class PathJsonVO : public JsonVO<PathDTO::Wrapper>
{
	DTO_INIT(PathJsonVO, JsonVO<PathDTO::Wrapper>);

};



#include OATPP_CODEGEN_END(DTO)

#endif 