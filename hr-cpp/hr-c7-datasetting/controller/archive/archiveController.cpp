#include "stdafx.h"
#include "ArchiveController.h"

// 分页查询数据
ArchivePageJsonVO::Wrapper ArchiveController::execQueryArchive(const ArchiveQuery::Wrapper& query, const PayloadDTO& payload)
{
    // 创建响应对象
    auto vo = ArchivePageJsonVO::createShared();
    // 创建分页对象
    auto pdto = ArchivePageDTO::createShared();
    // 响应结果
    vo->success(pdto);
    return vo;
}

// 新增数据
Uint64JsonVO::Wrapper ArchiveController::execAddArchive(const ArchiveDTO::Wrapper& dto)
{
    // 定义返回数据对象
    auto jvo = Uint64JsonVO::createShared();
   
    // 响应结果
    jvo->success(1);
    return jvo;
}
// 修改数据
Uint64JsonVO::Wrapper ArchiveController::execModifyArchive(const ArchiveDTO::Wrapper& dto)
{
    // 创建响应对象
    auto vo = Uint64JsonVO::createShared();
    // 响应结果
    vo->success(1);
    return vo;
}

// 删除数据
Uint64JsonVO::Wrapper ArchiveController::execRemoveArchive(const ArchiveDTO::Wrapper& dto)
{
    // 创建响应对象
    auto vo = Uint64JsonVO::createShared();
    
    // 响应结果
    vo->success(1);
    return vo;
}