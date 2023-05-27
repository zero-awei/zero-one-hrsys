#include "stdafx.h"
#include "DeclareTypeListDAO.h"

list<DeclareTypeDO> DeclareTypeListDAO::getDeclareTypeList()
{
	list<DeclareTypeDO> lists = {};
	for (char i = 'A'; i <= 'Z'; i++) {
		DeclareTypeDO temp;
		temp.setDeclaretype(to_string(i));
		lists.push_back(temp);
	}
	return lists;
}
