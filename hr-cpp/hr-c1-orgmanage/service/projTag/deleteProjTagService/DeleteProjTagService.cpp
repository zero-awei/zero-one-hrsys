#include "stdafx.h"
#include "DeleteProjTagService.h"
#include "dao/projTag/DeleteProjTagDAO.h"

bool DeleteProjTagService::removeData(string id)
{
	DeleteProjTagDAO deleteProjTagDAO;
	return deleteProjTagDAO.deleteById(id) == 1;
}

bool DeleteProjTagService::removeBatchData(const DeleteProjTagBatchDTO::Wrapper& deleteBatchProjTagDTO)
{
	DeleteProjTagDAO deleteProjTagDAO;
	auto sqlSession = deleteProjTagDAO.getSqlSession();
	sqlSession->beginTransaction();
	bool isSuccess = true;
	for (const auto& item : *deleteBatchProjTagDTO->tagIds) {
		if (deleteProjTagDAO.deleteById(item->c_str()) != 1)
		{
			sqlSession->rollbackTransaction();
			isSuccess = false;
			return isSuccess;
		}
	}
	sqlSession->commitTransaction();
	return isSuccess;
}