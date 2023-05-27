#include "stdafx.h"
#include "PatentinfoService.h"
#include "../../dao/patentinfo/PatentinfoDAO.h"

//查询所有数据
PatentinfoDTO::Wrapper PatentinfoService::listAll(const PatentinfoQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PatentinfoDTO::createShared();
	//pages->pageIndex = query->pageIndex;
	//pages->pageSize = query->pageSize;

	// 查询数据总条数
	PatentinfoDAO dao;
	/*uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}*/

	// 分页查询数据
	//pages->total = count;
	//pages->calcPages();
	list<PatentinfoDO> result = dao.selectByPIMPATENTID(query);
	//将DO转换成DTO
	for (PatentinfoDO sub : result)
	{
		auto dto = PatentinfoDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, zlh, ZLH,
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
			//pages->addData(dto);

	}
	return pages;
}


// //保存数据
//uint64_t SampleService::saveData(const SampleDTO::Wrapper& dto)
//{
//	// 组装DO数据
//	SampleDO data;
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
//		// 执行数据添加
//		SampleDAO dao;
//	return dao.insert(data);
//}

// 修改数据
bool PatentinfoService::updateData(const PatentinfoDTO::Wrapper& dto)
{
	// 组装DO数据
	PatentinfoDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, ZLH, zlh,
										UPDATEDATE, updatedate,
										PIMPATENTID, pimpatentid,
										ZLHQSJ, zlhqsj,
										PIMPATENTNAME, pimpatentname,
										UPDATEMAN, updateman,
										CREATEMAN, createman,
										CREATEDATE, createdate,
										ZLPZGB, zlpzgb,
										PIMPERSONID, pimpersonid,
										JLSS, jlss,
										JLSPZT, jlspzt,
										JLGLBH, jlglbh,
										JLCZZ, jlczz,
										ENCLOLURE, enclolure,
										REASON, reason)
		// 执行数据修改
		PatentinfoDAO dao;
	return dao.update(data) == 1;
}



// 通过ID删除数据
//bool SampleService::removeData(uint64_t id)
//{
//	SampleDAO dao;
//	return dao.deleteById(id) == 1;
//}
