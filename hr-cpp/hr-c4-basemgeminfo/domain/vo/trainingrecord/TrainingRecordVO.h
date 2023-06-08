#pragma once
#ifndef _TRAININGRECORDVO_H_
#define _TRAININGRECORDVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/trainingrecord/TrainingRecordDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class TrainingRecordPageJsonVO : public JsonVO<TrainingRecordPageDTO::Wrapper> {
	DTO_INIT(TrainingRecordPageJsonVO, JsonVO<TrainingRecordPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif