//档案室层级下拉列表（因为MySQL没有对应的表，所以直接推进去）
//作者：狗皮电耗子
//2023年5月26日
#include "stdafx.h"
#include "ArchivesLevelsDAO.h"

list<ArchivesLevelDO> ArchivesLevelsDAO::getArchivesLevels() {
	list<ArchivesLevelDO> lists={};
	ArchivesLevelDO a, b ,c;

	a.setArchivesLevel("上层");
	lists.push_back(a);

	b.setArchivesLevel("中层");
	lists.push_back(b);

	c.setArchivesLevel("下层");
	lists.push_back(c);

	return lists;
}

