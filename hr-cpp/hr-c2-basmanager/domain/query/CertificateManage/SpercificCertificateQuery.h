
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _SPERCIFIC_CERTIFIDATE_QUERY_
#define _SPERCIFIC_CERTIFIDATE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SpercificCertificateQuery : public PageQuery
{
	DTO_INIT(SpercificCertificateQuery, PageQuery);
	// ���
	DTO_FIELD(String, PIMVOCATIONALID);
	DTO_FIELD_INFO(PIMVOCATIONALID) {
		info->description = ZH_WORDS_GETTER("spercificcertificate.field.PIMVOCATIONALID");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif
