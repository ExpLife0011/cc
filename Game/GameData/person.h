#pragma once
#include "monster.h"
#include "BufferService.h"
#include "SkillService.h"
class person :
	public monster
{
public:
	person(DWORD dwNodeBase);
	~person();

	//��ȡ����չ�����
	float GetAttackDistance()const;
	//��ȡ��ҹ����ٶ�
	float GetAttackSpeed()const;
	//��ȡ�ƶ��ٶ�
	float GetMoveSpeed()const;
	//��ȡ��ҹ�����
	float GetAggressivity()const;

	std::shared_ptr<CSkillService> GetSkillService();

private:
	std::shared_ptr<CSkillService> m_skillService;
};

