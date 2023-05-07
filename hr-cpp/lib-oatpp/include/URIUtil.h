#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/06 19:27:45

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
#ifndef _URIUTIL_H_
#define _URIUTIL_H_
#include <string>

/**
 * URI编码解码工具
 */
class URIUtil
{
private:
	static std::string charToHex(unsigned char c);
	static unsigned char hexToChar(const std::string& str);
public:
	// url编码
	static std::string urlEncode(const std::string& toEncode);
	// url解码
	static std::string urlDecode(const std::string& toDecode);
};

#endif // _URIUTIL_H_