/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 23:23:22
 
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
#include "TestToken.h"
#include "JWTUtil.h"
#include <iostream>

void TestToken::generateToken()
{
	PayloadDTO p;
	p.getAuthorities().push_back("SUPER_ADMIN");
	p.setUsername(u8"roumiou");
	p.setId("1");
	p.setExp(3600 * 30);
	std::cout << JWTUtil::generateTokenByRsa(p, RSA_PRIV_KEY->c_str()) << std::endl;
}
