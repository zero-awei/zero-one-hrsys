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
#ifndef _ARCHIVESDO_H_
#define _ARCHIVESDO_H_

#include "../DoInclude.h"

class ArchivesDO {
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(string, dabh, Dabh);
	CC_SYNTHESIZE(string, ormorgid3, Ormorgid3);
	CC_SYNTHESIZE(string, dabgd, Dabgd);
	CC_SYNTHESIZE(string, archivescenterid, Archivescenterid);
	CC_SYNTHESIZE(string, education, Education);
	CC_SYNTHESIZE(string, dateofbirth, Dateofbirth);
	CC_SYNTHESIZE(string, joinpartydate, Joinpartydate);
	CC_SYNTHESIZE(string, startworkdatae, Startworkdatae);
	CC_SYNTHESIZE(string, dgzt, Dazt);


};

#endif // !_ARCHIVESDO_H_