#include "stdafx.h"
#include "DeleteProjTagController.h"


Uint64JsonVO::Wrapper DeleteProjTagController::execDeleteByTagId(const DeleteProjTagDTO::Wrapper& deleteProjTagQuery, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	return vo;
}

Uint64JsonVO::Wrapper DeleteProjTagController::execDeleteBatchByTagId(const DeleteProjTagBatchDTO::Wrapper& deleteProjTagQuery, const PayloadDTO& payload)
{
	auto vo = Uint64JsonVO::createShared();
	return vo;
}