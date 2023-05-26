#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tml
 @Date: 2022/10/25 11:52:32

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
#ifndef _PIMPAPER_DO_
#define _PIMPAPER_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class PimpaperDO
{
	//��������
	CC_SYNTHESIZE(string, pimpapername, Pimpapername);

	//������
	CC_SYNTHESIZE(string, cbs, Cbs);

	//��������
	CC_SYNTHESIZE(string, kwmc, Kwmc);

	//��������
	CC_SYNTHESIZE(string, gwqs, Gwqs);

	//����ʱ��
	CC_SYNTHESIZE(string, fbsj, Fbsj);

	//���������������е�����
	CC_SYNTHESIZE(int, grzlwzzzdpm, Grzlwzzzdpm);

	//����
	CC_SYNTHESIZE(string, fj, Fj);
public:
	PimpaperDO() {
		pimpapername = "";
		cbs = "";
		kwmc = "";
		gwqs = "";
		fbsj = "";
		grzlwzzzdpm = 0;
		fj = "";
	}
};

#endif // !_PIMPAPER_DO_