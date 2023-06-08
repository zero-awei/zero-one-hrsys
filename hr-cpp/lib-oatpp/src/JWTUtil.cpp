/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 14:37:50

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
#include <iostream>
#include "JWTUtil.h"

// 定义一个测试RSA私钥
std::unique_ptr<std::string> RSA_PRIV_KEY = std::make_unique<std::string>(R"(
-----BEGIN PRIVATE KEY-----
MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQDYJSiDqR0pQ6U6
104cVyy2zQoe3l6DxQ8XpiP+O17uODE5axgHnvWt0zNMMhijVQhphU4lx3eiKj1C
V5tRkPs7gYvygmaP2s0JWTrTF/He+FghLN0dvBCFRSDH5gOYOvlQlX8P+6EJ0UrO
JNQEyMOi1JBe8KxtYgwYYQVs9cp71VGaCq2N019a+MxruylDCLLSCPsZ45SIi22R
VmdrqoUVlFJEDGnc0n0Qttxbsp327kgXOu/Fc2Jg860iLD7OolNixJdQlMjthABf
L3Ooa1PtBQVSPFR/7tvUMQukZk+bAZ3knOP7N9M2xLcNE249Ak+Q9ulSjWoKxTnm
xeBw2t/PAgMBAAECggEADHXH6h8boT9XDRdQV23nE/qp9LGY/Tuk7RYUyRkfFdiD
be3wiq/tNcIRGPliVjgWrg6TPLZM/To2IdbvCzqyYPHM4YQG6ZARddKBA55DwTjL
y83MSWSIB0a+5wcpeeMccDrOAlvdIrW//DY/Sq9QJ9jdIbv6FKwsSlN9fpSEwbKl
TDqwZJCyc5KBKq7r6NixO/ksATi1uaQUfJT5b4sakGKUN5I7MwAjST4em7Ze8VVc
HGt1ClaTgLxKfPMurd0Ec+8o/3ex/PkU7Wx8AHqAj/IQsLdNB2arHePpcQVzHjsb
u4+zJSrtxOzrZlC/qfPObh8+o/i72K556ZfcEFjb8QKBgQDt2qD5sKn592+xtGXX
rzv/8G1CdE6Zy4WBUl33gov2rbGvmkrAeDGWV7dgTW0fPI9oXhV4Ioc7q61cDp8C
U9FDjDNpEEhUextq4VFjJWQ2tUvigyTkMFT7dEg1j35jbMGmvNh9jWQzdeM3Rheb
Q8VVGbZ5i2z4iGpfrDfStUeiiwKBgQDooow36Y5KZtvbnkF+C0nqQ7LC63ZsSBTS
UQgFWw5sBJssv9DsZIm1Ke14aHZftrDm67mg+/xsrw3+DZxwlaui8zA4PLpmTrGj
AnJ/2F9En8LZtb/ove+gXuQjZrNUsHh6+OpMWaEC1Flp3+jaPoaKZPp0ta/WYHPi
OEQ3uvh0TQKBgH0FvjeAtNe/R+aQfDey1EbjiYq0t9v/Ll2bfejrpcYz5oH3B/PD
Oc1crfbgu8r/eiHR0lcjTxH+W1FYHhyLEiP/Pcar2FkPnInBhZYnwVVAVnLpnCqV
fRXvOUVt93EraV7LRMA54cFq5dPX8/CY3tCsg03AC7dXfRJs46rNvqmhAoGACyR1
+Nub8B5bG3rKAkKCKNFTR5jFlEwjiytMag1BdJUH5a3OUPRD0ESQ1jqSqOT0NitG
Odq37XC5B9kZDB9vGB/zyE3IU8wjH/6nA06WyY+pYoodBgXK63CAFt39auoE60bu
2fdVCfCn07Vgzss94HUTtfFZ2bfG9SfixJSU/+UCgYEAyW1Si7qQRiNUSJWU8Jae
yFWOL1mvZRpXPUlg70H4wARoJjK6XgNKcE6GWbOedNtyiVJ7b07bmf9YJX2NWOzE
913vLOeLSlJeJAoQHEoYCM0nnOEcfUMiuOx59R4zk4RzSC64uK9PeguGSS6RaQwQ
8aj6l5u1SVtUNRb+ZjPCU8c=
-----END PRIVATE KEY-----)");

#define JU_VERIFY_CATCH(__p__) \
catch (const jwt::TokenExpiredError& e) { \
	std::cerr << "TokenExpiredError:" << e.what() << std::endl; \
	__p__.setCode(PayloadCode::TOKEN_EXPIRED_ERROR); \
} \
catch (const jwt::SignatureFormatError& e) { \
	std::cerr << "SignatureFormatError:" << e.what() << std::endl; \
	__p__.setCode(PayloadCode::SIGNATUREFORMAT_ERROR); \
} \
catch (const jwt::DecodeError& e) { \
	std::cerr << "DecodeError:" << e.what() << std::endl; \
	__p__.setCode(PayloadCode::DECODE_ERROR); \
} \
catch (const jwt::VerificationError& e) { \
	std::cerr << "VerificationError:" << e.what() << std::endl; \
	__p__.setCode(PayloadCode::VERIFICATION_ERROR); \
} \
catch (const std::exception& e) { \
	std::cerr << "OtherError:" << e.what() << std::endl; \
	__p__.setCode(PayloadCode::OTHER_ERROR); \
}

std::string JWTUtil::md5(const std::string& src)
{
	MD5_CTX ctx;
	std::string md5_string;
	unsigned char md[16] = { 0 };
	char tmp[33] = { 0 };
	MD5_Init(&ctx);
	MD5_Update(&ctx, src.c_str(), src.size());
	MD5_Final(md, &ctx);
	for (int i = 0; i < 16; ++i)
	{
		memset(tmp, 0x00, sizeof(tmp));
		snprintf(tmp, sizeof(tmp), "%02X", md[i]);
		md5_string += tmp;
	}
	return md5_string;
}

std::string JWTUtil::generateTokenByHmac(const PayloadDTO& payloadDto, const std::string& secretStr)
{
	//1 创建JWT头，设置签名算法和类型
	jwt_header hdr = jwt_header{ jwt::algorithm::HS256 };
	//2 将负载信息封装到Payload中
	jwt::jwt_payload jp;
	//2.1 呼叫属性转换
	payloadDto.propToJwt(&jp);
	//2.2 失效时间在内部处理
	jp.add_claim("exp", std::chrono::system_clock::now() + std::chrono::seconds{ payloadDto.getExp() });
	//3 创建HMAC签名器
	jwt::jwt_signature sgn{ md5(secretStr) };
	std::error_code ec{};
	//4 生成token
	auto res = sgn.encode(hdr, jp, ec);
	return res;
}

PayloadDTO JWTUtil::verifyTokenByHmac(const std::string& token, const std::string& secretStr)
{
	PayloadDTO p;
	using namespace jwt::params;
	try {
		jwt_object dec_obj = jwt::decode(token, algorithms({ "HS256" }), secret(string_view(md5(secretStr))), verify(true));
		// 呼叫属性转换
		p.propToPayload(&dec_obj);
		// 失效时间在内部处理
		p.setExp(dec_obj.payload().get_claim_value<int64_t>("exp"));
	}
	JU_VERIFY_CATCH(p);
	return p;
}

std::string JWTUtil::generateTokenByRsa(const PayloadDTO& payloadDto, const std::string& rsaPriKey)
{
	jwt::jwt_object obj;
	obj.secret(rsaPriKey);
	obj.header().algo(jwt::algorithm::RS256);
	// 呼叫属性转换
	payloadDto.propToJwt(&obj);
	// 失效时间在内部处理
	obj.add_claim("exp", std::chrono::system_clock::now() + std::chrono::seconds{ payloadDto.getExp() });
	return obj.signature();
}

PayloadDTO JWTUtil::verifyTokenByRsa(const std::string& token, const std::string& rsaPubKey)
{
	PayloadDTO p;
	using namespace jwt::params;
	try {
		jwt_object dec_obj = jwt::decode(token, algorithms({ "RS256" }), secret(rsaPubKey), verify(true));
		// 呼叫属性转换
		p.propToPayload(&dec_obj);
		// 失效时间在内部处理
		p.setExp(dec_obj.payload().get_claim_value<int64_t>("exp"));
	}
	JU_VERIFY_CATCH(p);
	return p;
}
