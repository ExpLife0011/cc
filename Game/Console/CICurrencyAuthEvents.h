// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ����

#import "E:\\workspace\\cc\\Game\\Console\\res\\AllpurAuthentic.dll" no_namespace
// CICurrencyAuthEvents ��װ����

class CICurrencyAuthEvents : public COleDispatchDriver
{
public:
	CICurrencyAuthEvents() {} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CICurrencyAuthEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CICurrencyAuthEvents(const CICurrencyAuthEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// _ICurrencyAuthEvents ����
public:
	void OnUpdate()
	{
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void OnInvalid()
	{
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void OnBulletin(LPCTSTR content)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, content);
	}

	// _ICurrencyAuthEvents ����
public:

};
