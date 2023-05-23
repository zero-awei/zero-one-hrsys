#pragma once
#ifndef _JOB_UPDATE_DTO_
#define _JOB_UPDATE_DTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class JobUpdateDTO : public oatpp::DTO
{
	DTO_INIT(JobUpdateDTO, DTO);
	//排序
	DTO_FIELD(UInt32, index);
	DTO_FIELD_INFO(index) {
		info->description = ZH_WORDS_GETTER("job.set.index");
	}
	//岗位名称
	DTO_FIELD(String, jobname);
	DTO_FIELD_INFO(jobname) {
		info->description = ZH_WORDS_GETTER("job.set.jobname");
	}
	//岗位类型
	DTO_FIELD(Boolean, jobtype);
	DTO_FIELD_INFO(jobtype) {
		info->description = ZH_WORDS_GETTER("job.set.jobtype");
	}
	//建议交流年限
	DTO_FIELD(UInt16, sugyear);
	DTO_FIELD_INFO(sugyear) {
		info->description = ZH_WORDS_GETTER("job.set.sugyear");
	}
	//必要交流年限
	DTO_FIELD(UInt16, nesyear);
	DTO_FIELD_INFO(nesyear) {
		info->description = ZH_WORDS_GETTER("job.set.nesyear");
	}
	//是否保密岗位
	DTO_FIELD(Boolean, isSecret);
	DTO_FIELD_INFO(isSecret) {
		info->description = ZH_WORDS_GETTER("job.set.isSecret");
	}
	//是否标准工时
	DTO_FIELD(Boolean, isStandard);
	DTO_FIELD_INFO(isStandard) {
		info->description = ZH_WORDS_GETTER("job.set.isStandard");
	}
	//是否关键岗位
	DTO_FIELD(Boolean, isKeywork);
	DTO_FIELD_INFO(isKeywork) {
		info->description = ZH_WORDS_GETTER("job.set.isKeywork");
	}
	//是否启用标识
	DTO_FIELD(Boolean, isId);
	DTO_FIELD_INFO(isId) {
		info->description = ZH_WORDS_GETTER("job.set.isId");
	}

public:
	JobUpdateDTO() {
		UInt32 index = 1;
		String jobname = "记得起名字（其实是想不出来）";
		Boolean jobtype = true;
		UInt16 sugyear = 5;
		UInt16 nesyear = 1;
		Boolean isSecret = false;
		Boolean isStandard = true;
		Boolean isKeywork = false;
		Boolean isId = true;
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_JOB_UPDATE_DTO_
