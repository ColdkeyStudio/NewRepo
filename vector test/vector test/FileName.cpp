/*通过iostream和运算符重载实现vector的各项功能
* 包括pushback、popback、size、begin、end、*/

#include<iostream>
using namespace std;

template<class T>
class MyVector {
public:
	typedef T value_type;
	typedef value_type* iterator;
	typedef value_type* pointer;
	typedef value_type& reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

public:
	MyVector(int len = 0) :m_Data(nullptr), start(nullptr), m_len(len), pos(0) {
		if (len > 0)
		{
			m_Data = new value_type[len];
			start = m_Data;
		}
	}
	~MyVector() {
		delete[]m_Data;
	}

	void push_back(const value_type& v) {
		if (m_len > pos)
		{
			*(start + pos) = v;
			++pos;
		}
		else
		{
			cout << "容量不足" << endl;
		}
	}

	inline value_type pop_back()
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

	value_type& operator[](int n)
	{
		if (n < pos)
		{
			return *(start + n);
		}
		else {
			cout << "数组越界" << endl;
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
	cout << "建新vector测试，push_back测试，运算符重载测试" << endl << "预期结果:0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "实测结果:";
	MyVector<int> vec(10);
	for (int i = 0; i < vec.size(); i++)
	{
		vec.push_back(i);
	}
	for (MyVector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "size测试" << endl << "预期结果:10" << endl;
	cout << "实测结果:" << vec.size() << endl;
	cout << "begin测试" << endl << "预期结果:0" << endl;
	cout << "实测结果:" << *vec.begin() << endl;
	cout << "end测试" << endl << "预期结果:9" << endl;
	cout << "实测结果:" << *(vec.end() - 1) << endl;
	cout << "pop_back测试" << endl << "预期结果:01234数组越界" << endl;
	for (int j = 0; j < 5; j++)
	{
		vec.pop_back();
	}
	cout << "实测结果:";
	for (int i = 0; i < 6; i++)
	{
		cout << vec[i];
	}
	cout << endl;
}

int main()
{
	vectest();
	return 0;
}