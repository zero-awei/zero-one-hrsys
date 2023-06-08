#include "stdafx.h"
#include "DeclareTypeService.h"

DeclareTypeListDTO::Wrapper DeclareTypeService::getDeclareTypes()
{
	auto dto = DeclareTypeListDTO::createShared();
	//查询申报类型下拉列表
	DeclareTypeListDAO dao;
	//获取列表
	list<DeclareTypeDO> data = dao.getDeclareTypeList();
	//DO转DTO
	for (auto tmp : data) {
		string str = tmp.getDeclareType();
		dto->declareList->push_back(DeclareDTO::createShared(str));
	}
	return dto;
}
