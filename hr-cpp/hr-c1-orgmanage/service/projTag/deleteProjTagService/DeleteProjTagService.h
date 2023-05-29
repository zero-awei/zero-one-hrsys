#pragma once
#ifndef _DELETEPROJTAGSERVICE_H_
#define _DELETEPROJTAGSERVICE_H_
#include <list>
#include "domain/dto/projTag/DeleteProjTagDTO.h"

/**
 * 项目标签 - 删除项目标签Service
 * 负责人 : 咫尺之书
 */
class DeleteProjTagService
{
public:
	bool removeData(string id);
	bool removeBatchData(const DeleteProjTagBatchDTO::Wrapper& deleteBatchProjTagDTO);
};

#endif // !_DELETEPROJTAGSERVICE_H_