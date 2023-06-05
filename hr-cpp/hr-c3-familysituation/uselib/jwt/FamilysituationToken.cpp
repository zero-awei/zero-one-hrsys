#include "stdafx.h"
#include "FamilysituationToken.h"
#include "JWTUtil.h"
#include <iostream>

void FamilysituationToken::generateToken()
{
	PayloadDTO p;
	p.getAuthorities().push_back("SUPER_ADMIN");
	p.setUsername(u8"Marvin");
	p.setId("1");
	p.setExp(3600 * 30);
	std::cout << JWTUtil::generateTokenByRsa(p, RSA_PRIV_KEY->c_str()) << std::endl;
}
