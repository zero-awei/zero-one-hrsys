#include "stdafx.h"
#include "TitleService.h"
#include "../../dao/Title/TitleDAO.h"
#include "domain/dto/Title/TitleDTO.h"

TitlePageDTO::Wrapper TitleService::listAll(const TitleQuery::Wrapper& query)
{
	auto pages = TitlePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	TitleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<TitleDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (TitleDO sub : result)
	{
		auto dto = TitleDTO::createShared();
		dto->id = sub.getId();
		dto->num = sub.getNum();
		dto->name = sub.getName();
		dto->dtype = sub.getDtype();
		dto->Ttype = sub.getTTtype();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub, id,Id, num, Num, name, Name,dtype, Dtype, Ttype, TTtype)
			pages->addData(dto);
	}
	return pages;
}

uint64_t TitleService::saveData(const TitleDTO::Wrapper& dto)
{
	// 组装DO数据
	TitleDO data;
	data.setId(dto->id.getValue({}));
	data.setNum(dto->num.getValue(""));
	data.setName(dto->name.getValue(""));
	data.setDtype(dto->dtype.getValue(""));
	data.setTTtype(dto->Ttype.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Num, num, Name, name, Dtype, dtype, TTtype, Ttype)
	// 执行数据添加
		TitleDAO dao;
	return dao.insert(data);
}

bool TitleService::updateData(const TitleDTO::Wrapper& dto)
{
		// 组装DO数据
		TitleDO data;
	 	data.setId(dto->id.getValue({}));
		data.setNum(dto->num.getValue(""));
	 	data.setName(dto->name.getValue(""));
	 	data.setDtype(dto->dtype.getValue(""));
		data.setTTtype(dto->Ttype.getValue(""));
		ZO_STAR_DOMAIN_DTO_TO_DO(data,dto,Id,id,Num,num,Name,name,Dtype,dtype,TTtype,Ttype)
		// 执行数据修改
		TitleDAO dao;
	return dao.update(data) == 1;
}
bool TitleService::removeData(uint32_t id)
{
	TitleDAO dao;
	return dao.deleteById(id) == 1;
}