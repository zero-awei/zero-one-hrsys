/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: awei
 @Date: 2022/10/24 15:45:36
 
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
#include "../include/CharsetConvertHepler.h"
#include <codecvt>
#include <iostream>
#include <wchar.h>

#ifdef LINUX
#include <stdlib.h>
#include <bits/locale_conv.h>
#endif


//×ª»»»º³åÇø´óÐ¡¶¨ÒåÎª1KB
#define CONVERT_BUFF_SIZE 1024

std::string CharsetConvertHepler::unicodeToUtf8(const std::wstring& wstr)
{
	std::string ret;
	try
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> wcv;
		ret = wcv.to_bytes(wstr);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ret;
}

std::wstring CharsetConvertHepler::utf8ToUnicode(const std::string& str)
{
	std::wstring ret;
	try
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> wcv;
		ret = wcv.from_bytes(str);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ret;
}

std::string CharsetConvertHepler::unicodeToAnsi(const std::wstring& wstr)
{
#ifdef LINUX
	setlocale(LC_CTYPE, "zh_CN.UTF-8");
	std::string ret;
	const wchar_t* src = wstr.data();
	char mbString[CONVERT_BUFF_SIZE];
	size_t size = wcstombs(mbString, src, CONVERT_BUFF_SIZE);
	if (size == static_cast<size_t>(-1))
	{
		printf("Couldn't convert string--invalid multibyte character.\n");
	}
	else
	{
		ret = mbString;
	}
	//setlocale(LC_ALL, "C");
	return ret;
#else
	setlocale(LC_ALL, "chs");
	std::string ret;
	const wchar_t* src = wstr.data();
	char mbString[CONVERT_BUFF_SIZE];
	size_t countConverted;
	errno_t err;
	//mbstate_t mbstate;
	//memset((void*)&mbstate, 0, sizeof(mbstate));
	//err = wcsrtombs_s(&countConverted, mbString, CONVERT_BUFF_SIZE, &src, _TRUNCATE, &mbstate);
	err = wcstombs_s(&countConverted, mbString, CONVERT_BUFF_SIZE, src, _TRUNCATE);
	if (err == EILSEQ)
	{
		std::cout << "×Ö·û´®ÖÐ´æÔÚ±àÂë´íÎó" << std::endl;
	}
	else if (err == STRUNCATE)
	{
		std::cout << "»º´æÇø²»×ã£¬×Ö·û´®¹ý³¤" << std::endl;
		ret = mbString;
	}
	else
	{
		ret = mbString;
	}
	setlocale(LC_ALL, "C");
	return ret;
#endif
}

std::wstring CharsetConvertHepler::ansiToUnicode(const std::string& str)
{
#ifdef LINUX
	setlocale(LC_CTYPE, "zh_CN.UTF-8");
	std::wstring ret;
	const char* src = str.data();
	wchar_t wcstr[CONVERT_BUFF_SIZE];
	size_t size = mbstowcs(wcstr, src, CONVERT_BUFF_SIZE);
	if (size == static_cast<size_t>(-1))
	{
		printf("Couldn't convert string--invalid multibyte character.\n");
	}
	else
	{
		ret = wcstr;
	}
	//setlocale(LC_CTYPE, "C");
	return ret;
#else
	setlocale(LC_ALL, "chs");
	std::wstring ret;
	const char* src = str.data();
	wchar_t wcstr[CONVERT_BUFF_SIZE];
	size_t countConverted;
	errno_t err;
	err = mbstowcs_s(&countConverted, wcstr, CONVERT_BUFF_SIZE, src, _TRUNCATE);
	if (err == EILSEQ)
	{
		std::cout << "×Ö·û´®ÖÐ´æÔÚ±àÂë´íÎó" << std::endl;
	}
	else if (err == STRUNCATE)
	{
		std::cout << "»º´æÇø²»×ã£¬×Ö·û´®¹ý³¤" << std::endl;
		ret = wcstr;
	}
	else
	{
		ret = wcstr;
	}
	setlocale(LC_ALL, "C");
	return ret;
#endif
}

std::string CharsetConvertHepler::utf8ToAnsi(const std::string& str)
{
	return unicodeToAnsi(utf8ToUnicode(str));
}

std::string CharsetConvertHepler::ansiToUtf8(const std::string& str)
{
	return unicodeToUtf8(ansiToUnicode(str));
}
