#ifndef _SAMPLE_VO_
#define _SAMPLE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/patentinfo/patentinfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * 专利显示JsonVO，用于响应给客户端的Json对象
 */
class PatentinfoJsonVO : public JsonVO<PatentinfoDTO::Wrapper> {
	DTO_INIT(PatentinfoJsonVO, JsonVO<PatentinfoDTO::Wrapper>);
};




/**
 * 专利分页显示JsonVO，用于响应给客户端的Json对象
 */ 
class PatentinfoPageJsonVO : public JsonVO<PatentinfoPageDTO::Wrapper> {
	DTO_INIT(PatentinfoPageJsonVO, JsonVO<PatentinfoPageDTO::Wrapper>);
};





#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_