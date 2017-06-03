#pragma once
#include <mutex>
#include "monster.h"
class GameCall
{
public:
	~GameCall();
	static GameCall* GetInstance();
	//��ȡ��Ϸʱ��
	float GetClientTickTime()const;
	//��ͨ����
	bool HeroAttack(DWORD dwNodeBase);
	//ʹ�ü���
	bool UserSkill(DWORD _index, const DWORD& mons);
	//HOOK����CALL
	bool HookUseSkill();
	PEM_POINT_3D GetMousePnt()const;
	bool FindWay(PEM_POINT_3D pnt);
private:
	static std::mutex m_mutex;
	static GameCall* m_pInstance;
private:
	GameCall();
	GameCall(const GameCall& cg);
	void operator= (const GameCall& cg);
};

void __stdcall SkillHookStub(const DWORD& skillObj, PFLOAT xyz, PDWORD monsObj);
void skillCall(DWORD skillObj, DWORD xyz, DWORD mons);