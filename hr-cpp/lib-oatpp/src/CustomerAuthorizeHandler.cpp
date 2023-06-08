/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/05 17:04:13

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
#include "pch.h"
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "../include/CustomerAuthorizeHandler.h"

// std::unique_ptr<std::string> RSA_PUB_KEY = std::make_unique<std::string>(R"(
// -----BEGIN PUBLIC KEY-----
// MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA2CUog6kdKUOlOtdOHFcs
// ts0KHt5eg8UPF6Yj/jte7jgxOWsYB571rdMzTDIYo1UIaYVOJcd3oio9QlebUZD7
// O4GL8oJmj9rNCVk60xfx3vhYISzdHbwQhUUgx+YDmDr5UJV/D/uhCdFKziTUBMjD
// otSQXvCsbWIMGGEFbPXKe9VRmgqtjdNfWvjMa7spQwiy0gj7GeOUiIttkVZna6qF
// FZRSRAxp3NJ9ELbcW7Kd9u5IFzrvxXNiYPOtIiw+zqJTYsSXUJTI7YQAXy9zqGtT
// 7QUFUjxUf+7b1DELpGZPmwGd5Jzj+zfTNsS3DRNuPQJPkPbpUo1qCsU55sXgcNrf
// zwIDAQAB
// -----END PUBLIC KEY-----)");

// RSA公钥
std::unique_ptr<std::string> RSA_PUB_KEY = nullptr;

CustomerAuthorizeObject::CustomerAuthorizeObject(PayloadDTO payload)
{
	this->payload = payload;
}

const PayloadDTO& CustomerAuthorizeObject::getPayload()
{
	return this->payload;
}

CustomerAuthorizeHandler::CustomerAuthorizeHandler()
{
	//读取公钥
	if (!RSA_PUB_KEY)
	{
		std::string pubKey = "";
		std::ifstream ifs("public.pem");
		if (ifs.is_open())
		{
			std::string tmp;
			while (std::getline(ifs, tmp))
			{
				pubKey += tmp + "\n";
			}
			ifs.close();
		}
		RSA_PUB_KEY = std::make_unique<std::string>(pubKey);
	}
}

std::shared_ptr<oatpp::web::server::handler::AuthorizationHandler::AuthorizationObject> CustomerAuthorizeHandler::authorize(const oatpp::String& token)
{
	// 解析凭证
	PayloadDTO payload = JWTUtil::verifyTokenByRsa(token, RSA_PUB_KEY->c_str());
	if (payload.getCode() != PayloadCode::SUCCESS) {
		std::stringstream ss;
		ss << "Token: check fail code <" << PayloadDTO::getCodeName(payload.getCode()) << ">.";
		throw std::logic_error(ss.str());
	}
	// 将数据存放到授权对象中
	return std::make_shared<CustomerAuthorizeObject>(payload);
}
