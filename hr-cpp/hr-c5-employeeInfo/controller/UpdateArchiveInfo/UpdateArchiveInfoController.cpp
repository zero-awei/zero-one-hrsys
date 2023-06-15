#include "stdafx.h"
#include "UpdateArchiveInfoController.h"

Uint64JsonVO::Wrapper UpdateArchiveInfoController::execUpdateArchiveInfo(const UpdateArchiveInfoDTO::Wrapper& dto) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}