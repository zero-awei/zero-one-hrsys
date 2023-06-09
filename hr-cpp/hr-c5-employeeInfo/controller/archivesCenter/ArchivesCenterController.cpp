#include "stdafx.h"
#include "ArchivesCenterController.h"

ArchivesCenterPageJsonVO::Wrapper ArchivesCenterController::execQueryArchivesCenter(const PageQuery::Wrapper& query)
{
    // Service
    auto jvo = ArchivesCenterPageJsonVO::createShared();
    //jvo->success(result);
    return jvo;
}
