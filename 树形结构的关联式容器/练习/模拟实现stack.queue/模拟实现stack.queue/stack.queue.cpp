#include<deque>
template<class T, class Con = deque<T>>
class stack
{
public:
	stack();
	void push(const T& x);
	void pop();
	T& top();
	const T& top()const;
	size_t size()const;
	bool empty()const;
private:
	Con _c;
};

template<class T, class Con = deque<T>>
class queue
{
public:
	queue();
	void push(const T& x);
	void pop();
	T& back();
	const T& back()const;
	T& front();
	const T& front()const;
	size_t size()const;
	bool empty()const;
private:
	Con _c;
};