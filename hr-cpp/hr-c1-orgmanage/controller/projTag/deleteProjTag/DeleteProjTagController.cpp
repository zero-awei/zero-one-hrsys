#include "stdafx.h"
#include "DeleteProjTagController.h"
#include "service/projTag/deleteProjTagService/DeleteProjTagService.h"

StringJsonVO::Wrapper DeleteProjTagController::execDeleteByTagId(const DeleteProjTagDTO::Wrapper& deleteProjTagDTO, const PayloadDTO& payload)
{
	auto vo = StringJsonVO::createShared();
	// 参数校验
	if (!deleteProjTagDTO->tagId)
	{
		vo->init(String(""), RS_PARAMS_INVALID);
		return vo;
	}
	DeleteProjTagService deleteProjTagService;

	// 执行数据删除
	if (deleteProjTagService.removeData(deleteProjTagDTO->tagId)) {
		vo->success(deleteProjTagDTO->tagId);
	}
	else
	{
		vo->fail(deleteProjTagDTO->tagId);
	}
	return vo;
}

DeleteProjTagBatchVO::Wrapper DeleteProjTagController::execDeleteBatchByTagId(const DeleteProjTagBatchDTO::Wrapper& deleteProjTagBatchDTO, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto vo = DeleteProjTagBatchVO::createShared();
	// 参数校验
	if (!deleteProjTagBatchDTO->tagIds)
	{
		vo->init(deleteProjTagBatchDTO, RS_PARAMS_INVALID);
		return vo;
	}
	DeleteProjTagService postDeleteService;

	// 执行数据删除
	if (postDeleteService.removeBatchData(deleteProjTagBatchDTO)) {
		vo->success(deleteProjTagBatchDTO);
	}
	else
	{
		vo->fail(deleteProjTagBatchDTO);
	}
	return vo;
}