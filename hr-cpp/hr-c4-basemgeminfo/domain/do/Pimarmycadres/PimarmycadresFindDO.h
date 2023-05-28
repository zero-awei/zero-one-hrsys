#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: huilai
 @Date: 2023/05/18 8:59:52

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
#ifndef _PIMARMYCADRESFINDPAGEDO_H_
#define _PIMARMYCADRESFINDPAGEDO_H_


	

class PimarmycadresFindDO
{
	// 编号
	CC_SYNTHESIZE(string, PIMID, pIMID);
	//	种类
	CC_SYNTHESIZE(string, FORM, fORM);
	// 级别
	CC_SYNTHESIZE(string, LEVEL, lEVEL);
	// 发生时间
	CC_SYNTHESIZE(string, OCCURTIME, oCCURTIME);
	//附件路径
	CC_SYNTHESIZE(string, ANNEXPATH, aNNEXPATH);
};

#endif 