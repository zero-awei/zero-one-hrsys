
#include "stdafx.h"
#include "PaperService.h"
#include "../../dao/paperinfo/PaperinfoDAO.h"



// 查询指定论文信息详情
PaperinfoDTO::Wrapper PaperService::listAll(const string& st)
{
	// 构建返回对象
	PaperinfoDAO dao;
	//查询数据
	list<PaperinfoDO> result = dao.selectBypimpaperid(st);
	//将DO转换成DTO
	auto dto = PaperinfoDTO::createShared();
	for (PaperinfoDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			grzlwzzzdpm, GRZLWZZZDPM,
			updateman, UPDATEMAN,
			pimpaperid, PIMPAPERID,
			createdate, CREATEDATE,
			updatedate, UPDATEDATE,
			createman, CREATEMAN,
			fbsj, FBSJ,
			pimpapername, PIMPAPERNAME,
			cbshkwmc, CBSHKWMC,
			pimpersonid, PIMPERSONID,
			fj, FJ,
			jlspzt, JLSPZT,
			jlglbh, JLGLBH,
			jlczz, JLCZZ,
			jlss, JLSS,
			cbs, CBS,
			kwmc, KWMC,
			kwqs, KWQS,
			reason, REASON )
	}
	return dto;
}

// 修改数据
bool PaperService::updateData(const PaperinfoDTO::Wrapper& dto)
{
	// 组装DO数据
	PaperinfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PIMPAPERNAME, pimpapername, CBS, cbs, KWMC, kwmc, KWQS, kwqs, FBSJ, fbsj, GRZLWZZZDPM, grzlwzzzdpm, FJ, fj, PIMPAPERID, pimpaperid)
		// 执行数据修改
		PaperinfoDAO dao;
	return dao.update(data) == 1;
}


