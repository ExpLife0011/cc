#pragma once
#include "base.h"
class equipment :
	public base
{
public:
	equipment(DWORD dwNodeBase);
	~equipment();
	//����
	virtual char* GetName()const;
	//��ȡ��Ʒ����
	DWORD GetCount()const;
	//��ȡװ��buff����
	DWORD GetEquBuffCount()const;
};

