#pragma once
#include "CShareStruct.h"
#include <mutex>
class CShareMemoryService
{
public:
	
	~CShareMemoryService();
	static CShareMemoryService* GetInstance();

	//�򿪹����ڴ�
	bool OpenShareMemory();
	//���ٹ����ڴ�
	bool DestoryShareMemory();
	//��ȡ�����ڴ�ָ��
	PSHARED_MEMORY_DATA GetShareMemoryPointer();
private:
	static std::mutex m_mutex;
	static CShareMemoryService* m_pInstance;
	PSHARED_MEMORY_DATA m_pShareMemoryPointer;
	HANDLE m_hMapping;
private:
	CShareMemoryService();
	CShareMemoryService(const CShareMemoryService& cs);
	void operator= (const CShareMemoryService& cs);
};

