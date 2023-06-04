#pragma once

#ifndef _REWARDANDPUNISHVO_H_
#define _REWARDANDPUNISHVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/rewardandpunish/RewardAndPunishDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class RewardAndPunishJsonVO : public JsonVO<RewardAndPunishDTO::Wrapper>
{
	DTO_INIT(RewardAndPunishJsonVO, JsonVO<RewardAndPunishDTO::Wrapper>);
};

class RewardAndPunishPageJsonVO : public JsonVO<RewardAndPunishPageDTO::Wrapper>
{
	DTO_INIT(RewardAndPunishPageJsonVO, JsonVO<RewardAndPunishPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif