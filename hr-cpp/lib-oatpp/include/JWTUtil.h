#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 13:59:13

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
#ifndef _JWT_UTIL_
#define _JWT_UTIL_
#include "jwt/jwt.hpp"
#include <openssl/md5.h>
#include <list>
#include <memory>
#include "domain/dto/PayloadDTO.h"
using namespace jwt;

/**
 * JWT工具类
 */
class JWTUtil
{
private:
	//对字符串进行MD5处理
	static std::string md5(const std::string& src);
public:
	//************************************
	// Method:    generateTokenByHmac
	// FullName:  JWTUtil::generateTokenByHmac
	// Access:    public static 
	// Returns:   std::string 返回Token字符串
	// Qualifier: 使用HMAC算法构建Token
	// Parameter: const PayloadDTO& payloadDto 负载信息对象
	// Parameter: const std::string& secretStr 秘钥
	//************************************
	static std::string generateTokenByHmac(const PayloadDTO& payloadDto, const std::string& secretStr);

	//************************************
	// Method:    verifyTokenByHmac
	// FullName:  JWTUtil::verifyTokenByHmac
	// Access:    public static 
	// Returns:   PayloadDTO 负载信息对象
	// Qualifier: 验证HMAC Token
	// Parameter: const std::string& token Token字符串
	// Parameter: const std::string& secretStr 秘钥
	//************************************
	static PayloadDTO verifyTokenByHmac(const std::string& token, const std::string& secretStr);

	//************************************
	// Method:    generateTokenByRsa
	// FullName:  JWTUtil::generateTokenByRsa
	// Access:    public static 
	// Returns:   std::string
	// Qualifier: 使用RSA Pem生成Token，密钥对在线生成工具：http://www.metools.info/code/c80.html
	// Parameter: const PayloadDTO& payloadDto 负载信息
	// Parameter: const std::string& rsaPriKey RSA私钥
	//************************************
	static std::string generateTokenByRsa(const PayloadDTO& payloadDto, const std::string& rsaPriKey);

	//************************************
	// Method:    verifyTokenByRsa
	// FullName:  JWTUtil::verifyTokenByRsa
	// Access:    public static 
	// Returns:   PayloadDTO
	// Qualifier: 验证RSA Pem Token
	// Parameter: const std::string& token Token字符串
	// Parameter: const std::string& rsaPubKey RSA公钥
	//************************************
	static PayloadDTO verifyTokenByRsa(const std::string& token, const std::string& rsaPubKey);
};

// 测试RSA私钥
extern std::unique_ptr<std::string> RSA_PRIV_KEY;
#endif // !_JWT_UTIL_
