/*ͨ��iostream�����������ʵ��vector�ĸ����
* ����pushback��popback��size��begin��end��*/

#include<iostream>
using namespace std;

template<typename T>
class MyVector {
public:
	typedef T value;
	typedef T* iterator;
	typedef T& reference;

public:
	MyVector(int len = 0) :m_Data(nullptr), start(nullptr), m_len(len), pos(0) {
		if (len>0)
		{
			m_Data = new value[len];
			start = m_Data;
		}
	}
	~MyVector() {
		delete[]m_Data; 
	}

	void push_back(const value& v) {
		if (m_len>pos)
		{
			*(start + pos) = v;
			++pos;
		}
		else
		{
			cout << "��������" << endl;
		}
	}

	inline value pop_back()
	{
		--pos;
		return *(start + pos);
	}

	int size()
	{
		return this->m_len;
	}

	iterator begin()
	{
		return this->start;
	}

	iterator end()
	{
		return this->start + pos;
	}

	value& operator[](int n)
	{
		if (n<pos)
		{
			return *(start + n);
		}
		else {
			cout << "����Խ��" << endl;
		}
	}

protected:
	iterator m_Data;
	iterator start;
	int m_len;
	int pos;
};

void vectest()
{
	cout << "����vector���ԣ�push_back���ԣ���������ز���" << endl << "Ԥ�ڽ��:0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "ʵ����:";
	MyVector<int> vec(10);
	for (int i = 0; i < vec.size(); i++)
	{
		vec.push_back(i);
	}
	for (MyVector<int>::iterator it=vec.begin();it!=vec.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "size����" << endl << "Ԥ�ڽ��:10" << endl;
	cout << "ʵ����:" << vec.size() << endl;
	cout << "begin����" << endl << "Ԥ�ڽ��:0" << endl;
	cout << "ʵ����:" << *vec.begin() << endl;
	cout << "end����" << endl << "Ԥ�ڽ��:9" << endl;
	cout << "ʵ����:" << *(vec.end()-1) << endl;
	cout << "pop_back����" << endl << "Ԥ�ڽ��:01234����Խ��" << endl;
	for (int j = 0; j < 5; j++)
	{
		vec.pop_back();
	}
	cout << "ʵ����:";
	for (int i = 0; i < 6; i++)
	{
		cout << vec[i];
	}
	cout << endl;
}

void main()
{
	vectest();
}