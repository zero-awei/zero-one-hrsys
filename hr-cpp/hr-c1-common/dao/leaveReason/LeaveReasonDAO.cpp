/*
 Copyright Zero One Star. All rights reserved.

 @Author: yuanxiang
 @Date: 2023/05/23 15:50:51

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
#include "LeaveReasonDAO.h"
#include "dao/leaveReason/LeaveReasonMapper.h"

std::list<LeaveReasonDO> LeaveReasonDAO::queryLeaveReasonList()
{
	string sql = "SELECT DISTINCT PCMREASONNAME, PX FROM t_pcmreason";
	LeaveReasonMapper mapper;
	return sqlSession->executeQuery<LeaveReasonDO, LeaveReasonMapper>(sql, mapper);
}