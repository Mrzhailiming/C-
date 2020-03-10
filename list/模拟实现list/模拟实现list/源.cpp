#include <iostream>
using namespace std;

template <class T>
class Node{
public:
	Node(const T& val = T())
		:_val(val)
		, _prev(nullptr)
		, _next(nullptr){
		;
	}
	Node<T> _prev;
	Node<T> _next;
	T _val;
};

template <class T>
class Itrator{
public:
	typedef Node<T> Node;
	typedef Node* pNode;
	Itrator(const T* ptr = nullptr)
		:_pNode(ptr){
		;
	}
	//����* ->
	T& operator*(){
		return *(_pNode->_val);
	}
	T* operator->(){
		return &(_pNode->_val);
	}
	//++ -- ����
	//ǰ��++
	Itrator<T>& operator++(){
		_pNode = _pNode->_next;
		return *this;
	}
	//����++
	Itrator<T> operator++(int){
		Itrator<T> tmp = this;
		_pNode = _pNode->_next;
		return tmp;
	}
	//ǰ��--
	Itrator<T>& operator--(){
		_pNode = _pNode->_prev;
		return *this;
	}
	//����--
	Itrator<T> operator--(int){
		Itrator<T> tmp = this;
		_pNode = _pNode->_prev;
		return tmp;
	}
	//����!= ==
	bool operator!=(const Itrator<T>& it){
		return _pNode != it->_pNode;
	}
	bool operator==(const Itrator<T>& it){
		return _pNode == it->_pNode;
	}

	pNode _pNode;
};

//int main(){
//
//	return 0;
//}