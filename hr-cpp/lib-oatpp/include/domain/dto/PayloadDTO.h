#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/22 20:18:53

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
#ifndef _PAYLOADDTO_H_
#define _PAYLOADDTO_H_
#include "jwt/jwt.hpp"

/**
 * 负载信息获取状态编码
 */
enum class PayloadCode
{
	// 信息验证处理成功
	SUCCESS,
	// Token已过期
	TOKEN_EXPIRED_ERROR,
	// 签名格式错误
	SIGNATUREFORMAT_ERROR,
	// 解密错误
	DECODE_ERROR,
	// 验证错误
	VERIFICATION_ERROR,
	// 其他错误
	OTHER_ERROR
};

/**
 * 负载信息实体类
 */
class PayloadDTO
{
public:
	// 获取状态码对应的枚举值名称
	static std::string getCodeName(PayloadCode code) 
	{
		switch (code)
		{
		case PayloadCode::SUCCESS:
			return "SUCCESS";
		case PayloadCode::TOKEN_EXPIRED_ERROR:
			return "TOKEN_EXPIRED_ERROR";
		case PayloadCode::SIGNATUREFORMAT_ERROR:
			return "SIGNATUREFORMAT_ERROR";
		case PayloadCode::DECODE_ERROR:
			return "DECODE_ERROR";
		case PayloadCode::VERIFICATION_ERROR:
			return "VERIFICATION_ERROR";
		case PayloadCode::OTHER_ERROR:
			return "OTHER_ERROR";
		default:
			return "NONE";
		}
	}
private:
	// 主体数据
	std::string sub;
	// 凭证有效时长（秒）
	int64_t exp;
	// 用户编号
	std::string id;
	// 用户名
	std::string username;
	// 用户拥有的权限
	std::list<std::string> authorities;
	// 数据状态系信息
	PayloadCode code;
public:
	PayloadDTO()
	{
		this->username = "";
		this->exp = 0;
		this->sub = "";
		this->setCode(PayloadCode::SUCCESS);
	}
	PayloadDTO(std::string _sub, int64_t _exp, std::string _username, std::list<std::string> _authorities) :
		sub(_sub), exp(_exp), username(_username), authorities(_authorities)
	{
		this->setCode(PayloadCode::SUCCESS);
	}
	
	// getter/setter
	std::string getSub() const { return sub; }
	void setSub(std::string val) { sub = val; }
	int64_t getExp() const { return exp; }
	void setExp(int64_t val) { exp = val; }
	std::string getUsername() const { return username; }
	void setUsername(std::string val) { username = val; }
	std::list<std::string>& getAuthorities() { return authorities; }
	void setAuthorities(std::list<std::string> val) { authorities = val; }
	PayloadCode getCode() const { return code; }
	void setCode(PayloadCode val) { code = val; }
	std::string getId() const { return id; }
	void setId(std::string val) { id = val; }

	// 添加权限
	void putAuthority(std::string authstr) { authorities.push_back(authstr); }
	
	// 将Payload的属性转换到jwt_object中
	// 注意：新增属性字段后需要维护此方法
	template<class T>
	void propToJwt(T* obj) const
	{
		// 转换权限列表
		obj->add_claim("authorities", authorities);
		// 转换用户名
		obj->add_claim("user_name", username);
		// 转换id
		obj->add_claim("id", id);
		// TIP：新增字段在后面补充即可
	}

	// 将jwt_object的属性转换到Payload中
	// 注意：新增属性字段后需要维护此方法
	void propToPayload(jwt::jwt_object* obj) 
	{
		// 获取负载信息
		auto payload = obj->payload();
		auto _payload = payload.create_json_obj();

		// 转换权限列表
		if (_payload.contains("authorities"))
			setAuthorities(payload.get_claim_value<std::list<std::string>>("authorities"));
		// 转换用户名
		setUsername(payload.get_claim_value<std::string>("user_name"));
		// 转换数字类型id
		if (_payload["id"].is_number()) 
			setId(std::to_string(_payload["id"].get<int64_t>()));
		// 转换字符串类型id
		else
			setId(_payload["id"].get<std::string>());
		// TIP：新增字段在后面补充即可
	}
};

#endif // !_PAYLOADDTO_H_