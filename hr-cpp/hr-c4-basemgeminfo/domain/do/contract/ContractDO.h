#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/05/17 13:50:53

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
#ifndef _CONTRACTDO_H_
#define _CONTRACTDO_H_

#include "../DoInclude.h"

class ContractDO
{
	CC_SYNTHESIZE(string, PIMPERSONID, _PIMPERSONID);
	CC_SYNTHESIZE(string, HTBH, _HTBH);
	CC_SYNTHESIZE(string, HTLX, _HTLX);
	CC_SYNTHESIZE(string, CONTRACTTYPE, _CONTRACTTYPE);
	CC_SYNTHESIZE(string, QSRQ, _QSRQ);
	CC_SYNTHESIZE(string, JSRQ, _JSRQ);
	CC_SYNTHESIZE(string, HTZT, _HTZT);
	CC_SYNTHESIZE(string, SYDQSJ, _SYDQSJ);
};

#endif // !_CONTRACTDO_H_