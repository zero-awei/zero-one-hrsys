#pragma once

#ifndef _T_PIMPAPER_DO_
#define _T_PIMPAPER_DO_
#include "../DoInclude.h"

/**
 * 论文信息实体类
 */
class t_pimpaperDO
{
	// 发表时间
	CC_SYNTHESIZE(string, fbsj, Fbsj);
	// 出版社
	CC_SYNTHESIZE(string, cbs, Cbs);
	// 刊物期数
	CC_SYNTHESIZE(int, kwqs, Kwqs);
	// 附件
	CC_SYNTHESIZE(string, fj, Fj);
	// 个人在论文著作中的排名
	CC_SYNTHESIZE(int, grzlwzzzdpm, Grzlwzzzdpm);
	// 刊物名称
	CC_SYNTHESIZE(string, kwmc, Kwmc);
	// 论文名称
	CC_SYNTHESIZE(string, pimpapername, Pimpapername);
public:
	t_pimpaperDO() {
		fbsj = "";
		cbs = "";
		kwqs = 0;
		fj = "";
		grzlwzzzdpm = 0;
		kwmc = "";
		pimpapername = "";
	}
};

#endif 