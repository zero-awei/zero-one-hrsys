#pragma once
#ifndef _T_PIMARCHIVES_DO_
#define _T_PIMARCHIVES_DO_
#include "../DoInclude.h"

/**
 * ��Ա���ڵ� ��������ʵ����
 */
class t_pimarchivesDO
{
	// �������
	CC_SYNTHESIZE(string, dabh, Dabh);
	// ����λid
	CC_SYNTHESIZE(string, ormorgid3, Ormorgid3);
	//����λ���ı��� λ�����ݱ�t_srforg
	CC_SYNTHESIZE(string, orgname, Orgname);
	// �������ܵ�
	CC_SYNTHESIZE(string, dabgd, Dabgd);
	// ������id
	CC_SYNTHESIZE(string, archivescenterid, Archivescenterid);
	//���������ı��� λ�����ݱ�t_archivescenter
	CC_SYNTHESIZE(string, archivescentername, Archivescentername);
	//����״̬
	CC_SYNTHESIZE(string, dazt, Dazt);
	//Ա��id
	CC_SYNTHESIZE(string, pimpersonid, Pimpersonid);
	//Ա����� λ�����ݱ�t_pimperson
	CC_SYNTHESIZE(string, ygbh, Ygbh);
	//Ա������ λ�����ݱ�t_pimperson
	CC_SYNTHESIZE(string, pimpersonname, Pimpersonname);
	//������λ
	CC_SYNTHESIZE(string, ormorgname, Ormorgname);
	//Ա��״̬ λ�����ݱ�t_pimperson
	CC_SYNTHESIZE(string, ygzt, Ygzt);
	//������
	CC_SYNTHESIZE(string, operations, Operations);


	// �Ƿ��½���
	CC_SYNTHESIZE(string, sfxjd, Sfxjd);
	//��ע
	CC_SYNTHESIZE(string, bz, Bz);
	//����ѧ��
	CC_SYNTHESIZE(string, education, Education);
	//������������
	CC_SYNTHESIZE(string, dateofbirth, Dateofbirth);
	//�����뵳ʱ��
	CC_SYNTHESIZE(string, joinpartydate, Joinpartydate);
	//�����μӹ���ʱ��
	CC_SYNTHESIZE(string, startworkdate, Startworkdate);
	//����
	CC_SYNTHESIZE(string, fj, Fj);
public:
	t_pimarchivesDO() {
		dabh = "";
		ormorgid3 = "";
		orgname = "";
		dabgd = "";
		archivescenterid = "";
		archivescentername = "";
		dazt = "";
		pimpersonid = "";
		ygbh = "";
		pimpersonname = "";
		ormorgname = "";
		ygzt = "";
		operations = "";
		sfxjd = "";
		bz = "";
		education = "";
		dateofbirth = "";
		joinpartydate = "";
		startworkdate = "";
		fj = "";
	}
};

#endif // !_T_PIMARCHIVES_DO_