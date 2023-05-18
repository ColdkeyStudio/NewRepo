/*参考stl源码编写，实现stlvector容器的各项功能
包括类型模板，运算符重载，内置迭代器，自动扩容*/

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
		destroy(start, finish); // 全域函式，見 2.2.3 節。
	deallocate(); // 這是 vector 的?個 member function
}
reference front() { return *begin(); } // 第?個元素
reference back() { return *(end() - 1); } // 最後?個元素
void push_back(const T& x) { // 將元素安插至最尾端
	if (finish != end_of_storage) {
		construct(finish, x); // 全域函式，見 2.2.3 節。
		++finish;
	}
	else
		insert_aux(end(), x); // 這是 vector 的?個 member function
}
void pop_back() { // 將最尾端元素取
};