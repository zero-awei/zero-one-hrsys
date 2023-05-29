#pragma once
#ifndef TERMINATIONREMINDERVO_H
#define TERMINATIONREMINDERVO_H
#include "../../GlobalInclude.h"
#include "../../dto/TerminationReminderDTO/TerminationReminderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class TerminationReminderJsonVO : public JsonVO<TerminationReminderDTO::Wrapper> {
	DTO_INIT(TerminationReminderJsonVO, JsonVO<TerminationReminderDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class TerminationReminderPageJsonVO : public JsonVO<TerminationReminderPageDTO::Wrapper> {
	DTO_INIT(TerminationReminderPageJsonVO, JsonVO<TerminationReminderPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif