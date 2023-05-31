
#include "stdafx.h"
#include "PaperService.h"
#include "../../dao/paperinfo/PaperinfoDAO.h"



// 查询指定论文信息详情
PaperDTO::Wrapper PaperService::listAll(const string& st)
{
	// 构建返回对象
	PaperinfoDAO dao;
	//查询数据
	list<t_pimpaperDO> result = dao.selectBypimpaperid(st);
	//将DO转换成DTO
	auto dto = PaperDTO::createShared();
	for (t_pimpaperDO sub : result)
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
bool PaperService::updateData(const PaperDTO::Wrapper& dto)
{
	// 组装DO数据
	t_pimpaperDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		GRZLWZZZDPM, grzlwzzzdpm,
		UPDATEMAN, updateman,
		PIMPAPERID, pimpaperid,
		CREATEDATE, createdate,
		UPDATEDATE, updatedate,
		CREATEMAN, createman,
		FBSJ, fbsj,
		PIMPAPERNAME, pimpapername,
		CBSHKWMC, cbshkwmc,
		PIMPERSONID, pimpersonid,
		FJ, fj,
		JLSPZT, jlspzt,
		JLGLBH, jlglbh,
		JLCZZ, jlczz,
		JLSS, jlss,
		CBS, cbs,
		KWMC, kwmc,
		KWQS, kwqs,
		REASON, reason)
		// 执行数据修改
		PaperinfoDAO dao;
	return dao.update(data) == 1;
}


