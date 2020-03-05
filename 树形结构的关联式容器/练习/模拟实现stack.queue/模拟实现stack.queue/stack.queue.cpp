#include <deque>
#include <iostream>
using namespace std;

template<class T, class Con = deque<T>>
class Stack
{
public:
	Stack(){
		;
	}
	void push(const T& x){
		_c.push_back(x);
	}
	void pop(){
		if (_c.empty() != 1)
			_c.pop_back();
	}
	T& top();
	const T& top()const{
		return _c.back();
	}
	size_t size()const{
		return _c.size();
	}
	bool empty()const{
		return _c.empty();
	}
private:
	Con _c;
};

template<class T, class Con = deque<T>>
class Queue
{
public:
	Queue(){
		;
	}
	void push(const T& x){
		_c.push_back(x);
	}
	void pop(){
		if (_c.empty() != 1)
			_c.pop_front();
	}
	T& back(){
		return _c.back();
	}
	const T& back()const{
		return _c.back();
	}
	T& front(){
		
			return _c.front();
	}
	const T& front()const{
		return _c.front();
	}
	size_t size()const{
		return _c.size();
	}
	bool empty()const{
		return _c.empty();
	}
private:
	Con _c;
};

int main(){
	Queue<int,deque<int>> q;
	q.push(1);
	q.push(2);
	q.pop();
	int ret = q.front();
	return 0;
}