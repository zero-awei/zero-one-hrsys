#include "stdafx.h"
#include "PatentinfoService.h"
#include "../../dao/patentinfo/PatentinfoDAO.h"

//查询所有数据
PatentinfoDTO::Wrapper PatentinfoService::listAll(const string& pimpatentid)
{
	// 构建返回对象
	PatentinfoDAO dao;
	// 查询数据
	list<PatentinfoDO> result = dao.selectByPIMPATENTID(pimpatentid);
	//将DO转换成DTO
	auto dto = PatentinfoDTO::createShared();
	for (PatentinfoDO sub : result)
	{
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			zlh, ZLH,
			updatedate, UPDATEDATE,
			pimpatentid, PIMPATENTID,
			zlhqsj, ZLHQSJ,
			pimpatentname, PIMPATENTNAME,
			updateman, UPDATEMAN,
			createman, CREATEMAN,
			createdate, CREATEDATE,
			zlpzgb, ZLPZGB,
			pimpersonid, PIMPERSONID,
			jlss, JLSS,
			jlspzt, JLSPZT,
			jlglbh, JLGLBH,
			jlczz, JLCZZ,
			enclolure, ENCLOLURE,
			reason, REASON)
	}
	return dto;
}


// 修改数据
bool PatentinfoService::updateData(const PatentinfoDTO::Wrapper& dto)
{
	// 组装DO数据
	PatentinfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ZLH, zlh, PIMPATENTNAME, pimpatentname, ZLHQSJ, zlhqsj, ZLPZGB, zlpzgb, ENCLOLURE, enclolure, PIMPATENTID, pimpatentid)
		// 执行数据修改
		PatentinfoDAO dao;
	return dao.update(data) == 1;
}


