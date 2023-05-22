#include "stdafx.h"
#include "ArchivesService.h"
#include "domain/do/archives/ArchivesDO.h"
uint64_t ArchivesService::saveData(const ArchivesDTO::Wrapper& dto)
{
    ArchivesDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
    
    return uint64_t();
}
bool ArchivesService::updateDate(const ArchivesDTO::Wrapper& dto)
{
    // 组装DO数据
    ArchivesDO data;
    ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id)

    return false;
}
