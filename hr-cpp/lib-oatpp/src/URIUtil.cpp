/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/06 19:30:32

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
#include <iomanip>
#include "../include/URIUtil.h"

std::string URIUtil::charToHex(unsigned char c)
{
	int16_t i = c;
	std::stringstream ss;
	ss << "%" << std::setw(2) << std::setfill('0') << std::hex << i;
	return ss.str();
}

unsigned char URIUtil::hexToChar(const std::string& str)
{
	int16_t c = 0;
	if (!str.empty()) {
		std::istringstream in(str);
		in >> std::hex >> c;
		if (in.fail()) {
			throw std::runtime_error("stream decode failure");
		}
	}
	return static_cast<unsigned char>(c);
}

std::string URIUtil::urlEncode(const std::string& toEncode)
{
	std::ostringstream out;
	for (std::string::size_type i = 0, len = toEncode.length(); i < len; ++i) {
		int16_t t = toEncode.at(i);
		if (
			t == 45 ||// hyphen
			(t >= 48 && t <= 57) || // 0-9
			(t >= 65 && t <= 90) || // A-Z
			t == 95 || // underscore
			(t >= 97 && t <= 122) || // a-z
			t == 126 // tilde
			) {
			out << toEncode.at(i);
		}
		else 
		{
			out << charToHex(toEncode.at(i));
		}
	}
	return out.str();
}

std::string URIUtil::urlDecode(const std::string& toDecode)
{
	std::ostringstream out;
	for (std::string::size_type i = 0, len = toDecode.length(); i < len; ++i) {
		if (toDecode.at(i) == '%') {
			std::string str(toDecode.substr(i + 1, 2));
			out << hexToChar(str);
			i += 2;
		}
		else 
		{
			out << toDecode.at(i);
		}
	}
	return out.str();
}
