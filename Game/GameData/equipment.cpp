#include "stdafx.h"
#include "equipment.h"


equipment::equipment(DWORD dwNodeBase): base(dwNodeBase)
{
}


equipment::~equipment()
{
}

char* equipment::GetName() const
{
	__try {

	}
	__except (1) {
		utils::GetInstance()->log("HXL: equipment::GetName()�����쳣��");
	}
	return nullptr;
}

DWORD equipment::GetCount() const
{
	__try {
		return utils::GetInstance()->read<DWORD>(GetNodeBase() + 0x4);
	}
	__except (1) {
		utils::GetInstance()->log("HXL: equipment::GetCount()�����쳣��");
	}
	return 0;
}

DWORD equipment::GetEquBuffCount() const
{
	__try {
		return utils::GetInstance()->read<DWORD>(GetNodeBase() + 0x8);
	}
	__except (1) {
		utils::GetInstance()->log("HXL: equipment::GetEquBuffCount()�����쳣��");
	}
	return 0;
}
