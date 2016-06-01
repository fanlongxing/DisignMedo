// ���ģʽ֮��Ԫģʽ
// ���̶ȵĹ���ϸ���ȶ���

#include <iostream>
#include <map>
#include <string>
using namespace std;

//#pragma warning (disable : 4786)

class CBook
{
public:
	string GetPublisher() {return m_strPublisher;}
	string GetWriter()	  {return m_strWriter;}
	string GetBookName()  {return m_strBookName;}
	int    GetBookID()    {return m_nBookID;}
	int    GetPrice()     {return m_nPrice;}

	void   SetPublisher(string strPublisher) {m_strPublisher = strPublisher;}
	void   SetWriter(string strWriter)       {m_strWriter = strWriter;}
	void   SetBookName(string strBookName)   {m_strBookName = strBookName;}
	void   SetBookID(int nBookID)            {m_nBookID = nBookID;}
	void   SetPrice(int nPrice)              {m_nPrice = nPrice;}
private:
	string m_strPublisher;
	string m_strWriter;
	string m_strBookName;
	int m_nBookID;
	int m_nPrice;
};

// FlyWeight Publisher
class CPublisherFlyWeight
{
public:
	CPublisherFlyWeight(string strPublisher) {m_strPublisher = strPublisher;}
	string GetPublisher() {return m_strPublisher;}
private:
	string m_strPublisher;
};

// FlyWeight Publisher Factory
class CPublisherFlyWeightFactory
{
public:
	CPublisherFlyWeight* CreatePublisher(string strKey)
	{
		CPublisherFlyWeight* pPublisherFlyWeight = NULL;
		map<string, CPublisherFlyWeight*>::iterator it;
		it = m_mapPublisher.find(strKey);

		// Already existed
		if (it != m_mapPublisher.end())
		{
			pPublisherFlyWeight = (*it).second;
			cout << "Already existed this publisher : " << pPublisherFlyWeight->GetPublisher() << endl;
			cout << "You saved " << strlen(pPublisherFlyWeight->GetPublisher().c_str()) << " BYTES Space!" << endl;
		}
		else
		{
			pPublisherFlyWeight = new CPublisherFlyWeight(strKey);
			m_mapPublisher[strKey] = pPublisherFlyWeight;
		}

		return pPublisherFlyWeight;
	}
private:
	map<string, CPublisherFlyWeight*> m_mapPublisher;
};

// FlyWeight Writer
class CWriterFlyWeight
{
public:
	CWriterFlyWeight(string strWriter) {m_strWriter = strWriter;}
	string GetWriter() {return m_strWriter;}
private:
	string m_strWriter;
};

// FlyWeight Writer Factory
class CWriterFlyWeightFactory
{
public:
	CWriterFlyWeight* CreateWriter(string strKey)
	{
		CWriterFlyWeight* pWriterFlyWeight = NULL;
		map<string, CWriterFlyWeight*>::iterator it;
		it = m_mapWriter.find(strKey);

		// Already existed
		if (it != m_mapWriter.end())
		{
			pWriterFlyWeight = (*it).second;
			cout << "Already existed this writer : " << pWriterFlyWeight->GetWriter().c_str() << endl;
			cout << "You saved " << strlen(pWriterFlyWeight->GetWriter().c_str()) << " BYTES Space!" << endl;
		}
		else
		{
			pWriterFlyWeight = new CWriterFlyWeight(strKey);
			m_mapWriter[strKey] = pWriterFlyWeight;
		}

		return pWriterFlyWeight;
	}
private:
	map<string, CWriterFlyWeight*> m_mapWriter;
};

void PrintBookInfo(CBook objBook)
{
	cout << "Book Name : "	<< objBook.GetBookName()			<< endl;
	cout << "Book ID : "	<< objBook.GetBookID()				<< endl;
	cout << "Book Price : "	<< objBook.GetPrice()				<< endl;
	cout << "Publisher : "  << objBook.GetPublisher().c_str()	<< endl;
	cout << "Writer : "     << objBook.GetWriter().c_str()		<< endl;
}

int main()
{
	CPublisherFlyWeightFactory PFFac;
	CWriterFlyWeightFactory	   WFFac;
	CBook Book1, Book2, Book3;

	Book1.SetBookName(string("<����ǳ��MFC>"));
	Book1.SetPublisher((PFFac.CreatePublisher("���ӹ�ҵ������")->GetPublisher()));
	Book1.SetWriter((WFFac.CreateWriter("���")->GetWriter()));
	Book1.SetBookID(1);
	Book1.SetPrice(1);
	PrintBookInfo(Book1);
	cout << endl;

	Book2.SetBookName(string("<STLԴ������>"));
	Book2.SetPublisher((PFFac.CreatePublisher("���ӹ�ҵ������")->GetPublisher()));
	Book2.SetWriter((WFFac.CreateWriter("���")->GetWriter()));
	Book2.SetBookID(2);
	Book2.SetPrice(2);
	PrintBookInfo(Book2);
	cout << endl;

	Book3.SetBookName(string("<���̽��C++����ģ��>"));
	Book3.SetPublisher((PFFac.CreatePublisher("���ӹ�ҵ������")->GetPublisher()));
	Book3.SetWriter((WFFac.CreateWriter("���")->GetWriter()));
	Book3.SetBookID(3);
	Book3.SetPrice(3);
	PrintBookInfo(Book3);

	return 0;
}
