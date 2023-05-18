/*�ο�stlԴ���д��ʵ��stlvector�����ĸ����
��������ģ�壬��������أ����õ��������Զ�����*/

#include<iostream>
using namespace std;
template <class T,class Alloc=alloc>
class myvec
{
public:
	typedef T			value_type;
	typedef value_type* pointer;
	typedef value_type* iterator;
	typedef value_type& reference;
	typedef size_t		size_type;
	typedef ptrdiff_t	difference_type;

protected:
	typedef simle_alloc<value_type, Alloc> data_allocator;

	iterator start;
	iterator finish;
	iterator end_of_storage;

	void insert_aux(iterator position, const T& x);
	void deallocate() {
		if (start)
			data_allocator::deallocate(start, end_of_storage - start);
	}
	void fill_initialize(size_type n, const T& value) {
		start = allocate_and_fill(n, value);
		finish = start + n;
		end_of_storage = finish;
	}
public:
	iterator begin() { return start; }
	iterator end() { return finish; }
	size_type size() const { return size_type(end() - begin()); }
	size_type capacity() const {
		return size_type(end_of_storage - begin());
	}
	bool empty() const { return begin() == end(); }
	reference operator[](size_type n) { return *(begin() + n); }
	vector() : start(0), finish(0), end_of_storage(0) {}
	vector(size_type n, const T& value) { fill_initialize(n, value); }
	vector(int n, const T& value) { fill_initialize(n, value); }
	vector(long n, const T& value) { fill_initialize(n, value); }
	explicit vector(size_type n) { fill_initialize(n, T()); }
	~vector()
		destroy(start, finish); // ȫ��ʽ��Ҋ 2.2.3 ����
	deallocate(); // �@�� vector ��?�� member function
}
reference front() { return *begin(); } // ��?��Ԫ��
reference back() { return *(end() - 1); } // ����?��Ԫ��
void push_back(const T& x) { // ��Ԫ�ذ�������β��
	if (finish != end_of_storage) {
		construct(finish, x); // ȫ��ʽ��Ҋ 2.2.3 ����
		++finish;
	}
	else
		insert_aux(end(), x); // �@�� vector ��?�� member function
}
void pop_back() { // ����β��Ԫ��ȡ
};