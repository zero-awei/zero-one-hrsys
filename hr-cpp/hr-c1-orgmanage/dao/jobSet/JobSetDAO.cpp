
#include "stdafx.h"
#include "JobSetDAO.h"


std::list<string> JobSetDAO::insertMultiData(const list<PostDetailDO>& dataList)
{
	std::list<string> ret;
	// 开始事务
	sqlSession->beginTransaction();
	
	// 从头开始遍历整个数据列表，中间有任何一个失败，就撤销
	for (auto it = dataList.begin(); it != dataList.end(); it++) {
		string sql = "INSERT INTO `t_ormpost` \
				(`ORMPOSTID`, `ORMORGID`,`ORMPOSTNAME`, `GWFL`, `ISCONFIDENTIAL`, `POSTNATURE`, `ISKEYPOSTION`, `STARTSTOPSIGN`)\
				VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
		// 成功，返回自增id
		// 失败，返回0
		int singleRet = sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s", \
			(*it).getOrmPostId(), (*it).getOrgId(), \
			(*it).getOrmOrgName(), (*it).getGwfl(), (*it).getIsConfidential(), (*it).getPostNature(),\
			(*it).getIsKeyPostion(), (*it).getStartStopSign());
		ret.push_back(std::to_string(singleRet));
		// 如果执行失败，回滚
		// 成功则继续
		/*if (singleRet == 0) {
			sqlSession->rollbackTransaction();
			return ret;
		}*/
	}

	// 提交事务
	sqlSession->commitTransaction();
	return ret;
}

