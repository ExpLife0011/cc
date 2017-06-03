#pragma once
#include "base.h"
class skill :
	public base
{
public:
	skill(DWORD dwIndex , DWORD dwNodeBase);
	~skill();
	//��ȡ��������
	virtual char* GetName() const;
	//��ȡ���ܵȼ�
	DWORD GetLevel()const;
	//�����Ƿ���ȴ
	bool BCoolDown()const;
	//��ȡ��������
	float GetExpendMp()const;
	//��ȡ���ܷ�Χ
	float GetSkillRange() const;
	//��ȡ���ܷ�Χ1
	float GetSkillRange1() const;
	//��ȡ���ܷ�Χ2
	float GetSkillRange2() const;
	//��ȡ��������
	DWORD GetIndex()const;
	//��ȡ����Ƿ����������� ������������ܣ�������Ƿ�Χ
	float GetSkillType()const;
	//��ȡ���ܻ�������
	float GetSkillGetAggressivity()const;
	//��ȡ���ܹ������ӳɱ���
	float GetSkillPlusProportion()const;

private:
	DWORD m_index;

};

