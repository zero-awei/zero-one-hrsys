#ifndef _J_PATENT_VO_
#define _J_PATENT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/J_patentinfo/J_PatentinfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)



/**
 * 专利显示JsonVO，用于响应给客户端的Json对象
 */
class J_PatentinfoJsonVO : public JsonVO<J_PatentinfoDTO::Wrapper> {
	DTO_INIT(J_PatentinfoJsonVO, JsonVO<J_PatentinfoDTO::Wrapper>);
};




/**
 * 专利分页显示JsonVO，用于响应给客户端的Json对象
 */ 
class J_PatentinfoPageJsonVO : public JsonVO<J_PatentinfoPageDTO::Wrapper> {
	DTO_INIT(J_PatentinfoPageJsonVO, JsonVO<J_PatentinfoPageDTO::Wrapper>);
};





#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_