#ifndef _Contract_VO_
#define _Contract_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Gosh/ContractDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ContractJsonVO : public JsonVO<ContractDTO_gs::Wrapper> {
	DTO_INIT(ContractJsonVO, JsonVO<ContractDTO_gs::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class ContractPageJsonVO : public JsonVO<ContractPageDTO_gs::Wrapper> {
	DTO_INIT(ContractPageJsonVO, JsonVO<ContractPageDTO_gs::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_