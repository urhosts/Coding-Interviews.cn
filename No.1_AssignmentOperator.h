#include <cstring>
#include <cstdio>
#include <iostream>

class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);

	//声明返回值的类型为引用，才可以允许连续赋值  
	CMyString& CMyString::operator=(const CMyString &str);

	void Print();

private:
	char* m_pData;
};

CMyString::CMyString(char *pData)//构造函数
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString &str)//拷贝构造函数
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()//析构函数
{
	delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString& str)//赋值运算符重载
{
	if (this == &str)
		return *this;
	delete[] m_pData;
	m_pData = nullptr;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

void CMyString::Print()
{
	printf("%s", m_pData);
}

void Test1()
{
	printf("Test1 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}

// 赋值给自己
void Test2()
{
	printf("Test2 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}

// 连续赋值
void Test3()
{
	printf("Test3 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.Print();
	printf(".\n");
}

