#pragma once
#include <memory>
#include <vector>
#include "person.h"
class CMonsterService
{
public:
	CMonsterService();
	~CMonsterService();
	void travse(const monster& role);

	//��ȡ���뷶Χ������ĵ������
	std::shared_ptr<person> GetNearleastPerson(const monster& role, float distance);
	//��ȡ���뷶Χ��Ѫ����͵����
	std::shared_ptr<person> GetHealthLeastPerson(const monster& role, float distance);
	//��ȡ���뷶Χ������ĵ��˹���
	std::shared_ptr<monster> GetNearleastMonster(const monster& role, float distance);
	//��ȡ���뷶Χ�����Ѫ���Ĺ���
	std::shared_ptr<monster> GetHealthleastMonster(const monster& role, float distance);
	//��ȡ��Χ�ڵ�Ӣ������
	std::vector<std::shared_ptr<person>> GetHeroListInRange(const monster& role, float distance);
	//��ȡ��Χ�ڵ�С������
	std::vector<std::shared_ptr<monster>> GetMonsterListInRange(const monster& role, float distance);
private:
	//�����б�
	std::vector<std::shared_ptr<person>> m_personList;
	//�����б�
	std::vector<std::shared_ptr<monster>> m_monsterList;
};

