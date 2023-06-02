/*
 Copyright Zero One Star. All rights reserved.

 @Author: Andrew211vibe
 @Date: 2023/05/27 8:24:55

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "JobSetDAO.h"

std::list<std::string> JobSetDAO::insertMultiJob(const std::list<PostDetailDO>& data)
{
	// 构建返回对象
	std::list<std::string> res;

	// 开启事务处理
	sqlSession->beginTransaction();

	// 调用新增岗位设置
	for (auto item : data)
	{
		// 调用单个新增
		string sql = "INSERT INTO `t_ormpost` (`ORMPOSTID`, `ORMPOSTNAME`, `ISKEYPOSTION`, `CREATEMAN`, \
		`UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`, `ORMORGID`, `GWTYPE`, `GWFL`, `ISCONFIDENTIAL`, \
`ISTEMP`, `POSTNATURE`, `STARTSTOPSIGN`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

		int row = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
			item.getOrmPostId(), item.getOrmPostName(), item.getIsKeyPostion(), item.getCreateMan(),
			item.getUpdateMan(), item.getCreateDate(), item.getUpdateDate(), item.getOrmOrgId(),
			item.getGwType(), item.getGwfl(), item.getIsConfidential(), item.getIsTemp(),
			item.getPostNature(), item.getStartStopSign());

		// 新增成功将id加入返回列表中
		if (row == 1)
		{
			res.push_back(item.getOrmPostId());
		}
		// 否则则回滚并返回失败
		else
		{
			sqlSession->rollbackTransaction();
			res.clear();
			return res;
		}
	}

	// 全部新增成功则提交并返回成功
	sqlSession->commitTransaction();
	return res;
}

bool JobSetDAO::insertJob(const PostDetailDO& data)
{
	stringstream ss;
	ss << "INSERT INTO `t_ormpost` (`ORMPOSTID`, `ORMPOSTNAME`, `ISKEYPOSTION`, `CREATEMAN`";
	ss << ", `UPDATEMAN`, `CREATEDATE`, `UPDATEDATE`, `ORMORGID`, `GWTYPE`, `GWFL`, `ISCONFIDENTIAL`";
	ss << ", `ISTEMP`, `POSTNATURE`, `STARTSTOPSIGN`, `NX`, `BXJLNX`) VALUE";
	ss << " (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	string sql = ss.str();
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%ui%ui", 
		data.getOrmPostId(), data.getOrmPostName(), data.getIsKeyPostion(), data.getCreateMan(), 
		data.getUpdateMan(), data.getCreateDate(), data.getUpdateDate(), data.getOrmOrgId(), 
		data.getGwType(), data.getGwfl(), data.getIsConfidential(), data.getIsTemp(), 
		data.getPostNature(), data.getStartStopSign(), data.getNx(), data.getBxjlnx());
}
