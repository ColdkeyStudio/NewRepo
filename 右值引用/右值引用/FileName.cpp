#include<iostream>
using namespace std;

class Student
{
public:
	char* name;
	int size;

	Student(int size = 0) :size(size), name(nullptr)
	{
		if (size > 0)
		{
			name = new char[size];
			for (int i = 0; i < size; i++)
			{
				name[i] = 'a';
			}
		}
	}

	//Éî¿½±´
	Student(const Student& stu)
	{
		size = stu.size;
		name = new char[size];
		for (int i = 0; i < size; i++)
		{
			name[i] = stu.name[i];
		}
		cout << "COPY CONSTRUCTOR" << endl;
	}

	^ Student()
	{
		delete name;
		cout << "DELETE" << endl;
	}
};