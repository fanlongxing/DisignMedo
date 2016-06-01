#include <iostream>
#include <cassert>
using namespace std;

// ׷MMģ��
class CPursuitMMTemplate
{
public:
	CPursuitMMTemplate(char* pszName)
	{
		assert(pszName);
		strcpy(m_szBuf, pszName);
		cout << "I'm " << pszName << endl;
	}
	bool PursuitMM()
	{
		// ʧ�ܴ������ڵ���3ʧ�ܣ�
		int nFailedTimes = 0;
		if (!Acquaint())
			nFailedTimes++;
		if (!Chat())
			nFailedTimes++;
		if (!Date())
			nFailedTimes++;

		if (nFailedTimes >= 3)
			return false;
		
		return true;
	}
	char* GetName() 
	{
		return m_szBuf;
	}
private:
	char m_szBuf[20];
// Atomic operations
protected:
	virtual bool Acquaint() = 0;
	virtual bool Chat()		= 0;
	virtual bool Date()		= 0;
};

// ������Bob
class CBob : public CPursuitMMTemplate
{
public:
	CBob(char* pszName) : CPursuitMMTemplate(pszName) {}
protected:
	virtual bool Acquaint()
	{
		cout << "�����̫����Բ����" << endl;
		// MM : "�׳գ�"
		return false;
	}
	virtual bool Chat()
	{
		cout << "�ۣ����ֱ��ʱ����ҵ�һ������" << endl;
		// MM : "�׳գ�"
		return false;
	}
	virtual bool Date()
	{
		cout << "�������㿴��Ӱ����" << endl;
		// MM : "ȥ���ɣ�"
		return false;
	}
};

// ���˵�Leo
class CLeo : public CPursuitMMTemplate
{
public:
	CLeo(char* pszName) : CPursuitMMTemplate(pszName) {}
protected:
	virtual bool Acquaint()
	{
		cout << "���������XXX��Ư������" << endl;
		// MM : "�ף����Ҿ�û����Ȥ����"
		return true;
	}
	virtual bool Chat()
	{
		cout << "��Ҫ����Ϸ������Ұ���" << endl;
		// MM : "��ƫ����"
		return true;
	}
	virtual bool Date()
	{
		cout << "���ϸպ�û�£�Ҫ���������ѹ��·�ɣ�" << endl;
		// MM : "�ߣ�С����"
		return true;
	}
};

void Pursuit(CPursuitMMTemplate* tPursuit)
{
	if (!tPursuit->PursuitMM())
	{	
		cout << tPursuit->GetName() << "Failed!" << endl;
	}
	else
	{
		cout << tPursuit->GetName() << "Succeed!" << endl;
	}
}

int main()
{
	CBob objBob("Bob");
	Pursuit(&objBob);

	CLeo objLeo("Leo");
	Pursuit(&objLeo);

	return 0;
}