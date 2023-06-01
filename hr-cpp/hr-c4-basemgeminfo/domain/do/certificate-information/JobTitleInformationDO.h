#pragma once
#ifndef _JOBTITLE_INFORMATION_DO_H_
#define _JOBTITLE_INFORMATION_DO_H_

#include "../DoInclude.h"

class JobTitleInformationDO
{
	CC_SYNTHESIZE(string, professoranalysis_name, Professoranalysis_name);
	CC_SYNTHESIZE(string, credentials_num, Credentials_num);
	CC_SYNTHESIZE(string, professor_grades, Professor_grades);
	CC_SYNTHESIZE(string, major, Major);
	CC_SYNTHESIZE(string, zchqrq, Zchqrq);
	CC_SYNTHESIZE(string, reviewbody, Reviewbody);
	CC_SYNTHESIZE(string, lssuingagency, Lssuingagency);
	CC_SYNTHESIZE(string, employtime, Employtime);
	CC_SYNTHESIZE(string, enable, Enable);
	CC_SYNTHESIZE(string, employeeid, Employeeid);
};

#endif

