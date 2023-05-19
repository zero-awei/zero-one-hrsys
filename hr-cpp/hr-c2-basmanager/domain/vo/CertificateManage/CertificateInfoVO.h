/*
 Copyright Zero One Star. All rights reserved.
 @Author: awei
 @Date: $DATE$ $HOUR$:$MINUTE$:$SECOND$
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
#ifndef _CERTIFICATE_INFO_VO_
#include "../../GlobalInclude.h"
#include "../../dto/CertificateManage/CertificateInfoDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class CertificateInfoJsonVO : public JsonVO<CertificateInfoDTO::Wrapper>
{
	DTO_INIT(CertificateInfoJsonVO, JsonVO<CertificateInfoDTO::Wrapper>);
};

/**
 * 离职员工分页传输对象
 */
class CertificateInfoPageJsonVO : public JsonVO<CertificateInfoPageDTO::Wrapper>
{
	DTO_INIT(CertificateInfoPageJsonVO, JsonVO<CertificateInfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 
