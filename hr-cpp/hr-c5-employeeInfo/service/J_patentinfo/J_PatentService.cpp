#include "stdafx.h"
#include "J_PatentService.h"
#include "../../dao/J_patentinfo/J_PatentinfoDAO.h"

//查询所有数据
J_PatentinfoDTO::Wrapper PatentService::listAll(const string& pimpatentid)
{
	// 构建返回对象
	PatentinfoDAO dao;
	// 查询数据
	list<J_PatentinfoDO> result = dao.selectByPIMPATENTID(pimpatentid);
	//将DO转换成DTO
	auto dto = J_PatentinfoDTO::createShared();
	for (J_PatentinfoDO sub : result)
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
			reason, REASON,

			orgid, ORGID,
			orgsectorid, ORGSECTORID,
			ormorgid, ORMORGID,
			ormorgsectorid, ORMORGSECTORID,
			pimpersonname, PIMPERSONNAME,
			ygbh, YGBH,

			enable,ENABLE
		)
	}
	return dto;
}


// 修改数据
bool PatentService::updateData(const ModifyPatentinfoDTO::Wrapper& dto)
{
	// 组装DO数据
	J_PatentinfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ZLH, zlh, PIMPATENTNAME, pimpatentname, ZLHQSJ, zlhqsj, ZLPZGB, zlpzgb, ENCLOLURE, enclolure, PIMPATENTID, pimpatentid,UPDATEDATE,updatedate, UPDATEMAN,updateman)
		// 执行数据修改
		PatentinfoDAO dao;
	return dao.update(data) == 1;
}


