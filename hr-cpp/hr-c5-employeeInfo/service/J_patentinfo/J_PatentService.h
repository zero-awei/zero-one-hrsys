#pragma once

#ifndef _J_PATENTINFO_SERVICE_
#define _J_PATENTINFO_SERVICE_
#include <list>
#include "domain/vo/J_patentinfo/J_PatentinfoVO.h"
#include "domain/dto/J_patentinfo/J_PatentinfoDTO.h"



/**
 * 专利服务实现
 */
class PatentService
{
public:
	// 查询所有数据
	J_PatentinfoDTO::Wrapper listAll(const string& pimpatentid);

	// 修改数据
	bool updateData(const ModifyPatentinfoDTO::Wrapper& dto);

};

#endif // !_PATENTINFO_SERVICE_
