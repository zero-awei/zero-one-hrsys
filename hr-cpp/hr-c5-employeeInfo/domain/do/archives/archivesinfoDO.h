#pragma once
#ifndef _ARCHIVES_INFO_DO_
#define _ARCHIVES_INFO_DO_
#include "../DoInclude.h"

/**
 * ָ������������
 */

class archivesinfoDO
{
	// ������Ϣ��ʶ
	CC_SYNTHESIZE(string, pimarchivesid, PIMARCHIVESID);
	// �������
	CC_SYNTHESIZE(string, dabh, DABH);
	// ����λ
	CC_SYNTHESIZE(string, orgname, ORGNAME);
	// �Ƿ��½���
	CC_SYNTHESIZE(string, sfxjd, SFXJD);
	// ������
	CC_SYNTHESIZE(string, archivescentername, ARCHIVESCENTERNAME);
	// �������ܵ�
	CC_SYNTHESIZE(string, dabgd, DABGD);
	// Ա������
	CC_SYNTHESIZE(string, pimpersonname, PIMPERSONNAME);
	// Ա�����
	CC_SYNTHESIZE(string, ygbh, YGBH);
	// ������λ
	CC_SYNTHESIZE(string, ormorgname, ORMORGNAME);
	// ����ѧ��
	CC_SYNTHESIZE(string, education, EDUCATION);
	// ������������
	CC_SYNTHESIZE(string, dateofbirth, DATEOFBIRTH);
	// �����뵳ʱ��
	CC_SYNTHESIZE(string, joinpartydate, JOINPARTYDATE);
	// �����μӹ���ʱ��
	CC_SYNTHESIZE(string, startworkdatae, STARTWORKDATAE);
	// ����״̬
	CC_SYNTHESIZE(string, dazt, DAZT);
	// ��ע
	CC_SYNTHESIZE(string, bz, BZ);
	// ����
	CC_SYNTHESIZE(string, fj, FJ);
public:
	archivesinfoDO() {
		pimarchivesid = "";
		dabh = "";
		orgname = "";
		sfxjd = "";
		archivescentername = "";
		dabgd = "";
		pimpersonname = "";
		ygbh = "";
		ormorgname = "";
		education = "";
		dateofbirth = "";
		joinpartydate = "";
		startworkdatae = "";
		dazt = "";
		bz = "";
		fj = "";
	}
};

#endif