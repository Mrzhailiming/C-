#include <iostream>

using namespace std;

// List的节点类
template<class T>
struct ListNode
{
	ListNode(const T& val = T())
	: _val(val)
	, _pPre(nullptr)
	, _pNext(nullptr){
		;
	}
	ListNode<T>* _pPre;
	ListNode<T>* _pNext;
	T _val;
};
//List的迭代器类
template<class T, class Ref, class Ptr>
class ListIterator
{
	typedef ListNode<T>* PNode;
	typedef ListIterator<T, Ref, Ptr> Self;
public:
	ListIterator(PNode pNode = nullptr)
		:_pNode(pNode){
		;
	}
	ListIterator(const Self& l)
		: _pNode(l._pNode){
		;
	}
	//返回val的引用
	T& operator*(){
		return _pNode->_val;
	}
	//返回val的地址
	T* operator->(){
		return &(_pNode->_val);
	}
	Self& operator++(){
		_pNode = _pNode->_pNext;
		return *this;
	}
	Self operator++(int){
		Self tmp = *this;
		_pNode = _pNode->_pNext;
		return tmp;
	}
	Self& operator--(){
		_pNode = _pNode->_pPre;
		return *this;
	}
	Self& operator--(int){
		Self tmp = *this;
		_pNode = _pNode->_pNext;
		return tmp;
	}
	bool operator!=(const Self& l){
		return _pNode != l._pNode;
	}
	bool operator==(const Self& l){
		return _pNode == l->_pNode;
	}
	PNode _pNode;
};
//list类
template<class T>
class list
{
	typedef ListNode<T> Node;
	typedef Node* PNode;
public:
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;
public:
	///////////////////////////////////////////////////////////////
	// List的构造
	list(){
		CreateHead();
	}
	//
	list(int n, const T& value = T()){
		CreateHead();
		PNode newNode, cur = _pHead;
		int i = 0;
		for (; i < n; ++i){
			newNode = new Node(value);
			cur->_pNext = newNode;
			newNode->_pPre = cur;
			newNode->_pNext = _pHead;
			_pHead->_pPre = newNode;
			cur = newNode;
		}
	}
	//迭代器构造函数
	template <class Iterator>
	list(Iterator first, Iterator last){
		CreateHead();
		while (first != last){
			push_back(*first);
			++first;
		}
	}
	//拷贝构造
	list(list<T>& l){
		CreateHead();
		list<T> tmp(l.begin(), l.end());
		swap(tmp);
	}
	list<T>& operator=(const list<T> l){
		clear();
		list<T> tmp(l.begin(), l.end());
		swap(tmp);
		return *this;
	}
	~list(){
		clear();
		delete _pHead;
		_pHead = nullptr;
	}
	///////////////////////////////////////////////////////////////
	// List Iterator
	iterator begin(){
		return iterator(_pHead->_pNext);
	}
	iterator end(){
		return iterator(_pHead);
	}
	const_iterator const_begin(){
		return const_iterator(_pHead->_pNext);
	}
	const_iterator const_end(){
		return const_iterator(_pHead);
	}
	///////////////////////////////////////////////////////////////
	// List Capacity
	size_t size()const{
		size_t count = 0;
		PNode cur = _pHead->_pNext;
		while (cur != _pHead){
			++count;
			cur = cur->_pNext;
		}
		return count;
	}
	bool empty()const{
		return _pHead->_pNext == _pHead;
	}
	////////////////////////////////////////////////////////////
	// List Access
	const T& front()const{
		return _pHead->_pNext->_val;
	}
	T& front(){
		return _pHead->_pNext->_val;
	}
	
	T& back(){
		return _pHead->_pPre;
	}
	const T& back()const{
		return _pHead->_pPre;
	}
	////////////////////////////////////////////////////////////
	// List Modify
	void push_back(const T& val){ 
		insert(end(), val);
	}
	void pop_back(){ 
		erase(--end()); 
	}
	void push_front(const T& val){ 
		insert(begin(), val);
	}
	void pop_front(){ 
		erase(begin()); 
	}
	// 在pos位置前插入值为val的节点
	iterator insert(iterator pos, const T& val){
		PNode pre = pos._pNode->_pPre;
		PNode next = pos._pNode;
		PNode newNode = new Node(val);
		pre->_pNext = newNode;
		newNode->_pPre = pre;
		newNode->_pNext = next;
		next->_pPre = newNode;
		return iterator(newNode);
	}
	// 删除pos位置的节点，返回该节点的下一个位置
	iterator erase(iterator pos){
		if (_pHead != _pHead->_pNext){
			PNode pre = pos._pNode->_pPre;
			PNode next = pos._pNode->_pNext;
			pre->_pNext = next;
			next->_pPre = pre;
			delete pos._pNode;
			pos._pNode = nullptr;
			return iterator(next);
		}
		return nullptr;
	}

	//清空链表
	void clear(){
		if (_pHead != _pHead->_pNext){
			PNode cur = _pHead->_pNext;
			PNode next = cur->_pNext;
			while (next != _pHead){
				delete cur;
				cur = next;
				next = next->_pNext;
			}
			delete cur;
			cur = nullptr;
		}
	}
	void swap(list<T>& l){
		PNode newNode, oldNode;
		//newNode 代表this, oldNode代表l
		newNode = _pHead->_pNext;
		oldNode = l._pHead->_pNext;
		//第一步: 相等数量的交换
		while (oldNode != l._pHead && newNode != _pHead){
			T& tmp = oldNode->_val;
			oldNode->_val = newNode->_val;
			newNode->_val = tmp;
			oldNode = oldNode->_pNext;
			newNode = newNode->_pNext;
		}
		//第二步: 判断多出来的那个
		if (oldNode != l._pHead){//this没有需要交换的了, 需要把l首尾相连
			l._pHead->_pPre = oldNode->_pPre;//oldNode的上一个元素是l的最后一个元素
			oldNode->_pPre->_pNext = l._pHead;
			//此时的newNode是_pHead, 需要更新到最后一个元素
			newNode = newNode->_pPre;
			while (oldNode != l._pHead){
				
				PNode cur = new Node(oldNode->_val);
				newNode->_pNext = cur;
				cur->_pPre = newNode;
				PNode des = oldNode;
				oldNode = oldNode->_pNext;
				delete des;
				newNode = cur;
			}
			_pHead->_pPre = newNode;
			newNode->_pNext = _pHead;
		}
		else if (newNode != _pHead){//l没有需要交换的了, 需要把this首尾相连
			_pHead->_pPre = newNode->_pPre;//newNode的上一个元素是this的最后一个元素
			newNode->_pPre->_pNext = _pHead;
			//此时的oldNode是l._pHead, 需要更新到最后一个元素
			oldNode = oldNode->_pPre;
			while (newNode != _pHead){

				PNode cur = new Node(newNode->_val);
				oldNode->_pNext = cur;
				cur->_pPre = oldNode;
				PNode des = newNode;
				newNode = newNode->_pNext;
				delete des;
				oldNode = cur;
			}
			l._pHead->_pPre = oldNode;
			oldNode->_pNext = l._pHead;
		}
	}
private:
	//创建头节点
	void CreateHead(){
		_pHead = new Node();
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
		_pHead->_val = T();
	}
	PNode _pHead;
};

void testInsert(){
	list<int> l;
	l.insert(l.begin(), 1);
	l.insert(l.begin(), 2);
	l.insert(l.begin(), 3);
	l.front();
}

void testN_Val(){
	list<int> l(10, 1);
	size_t s = l.size();
}

void testErase(){
	list<int> l;
	l.insert(l.begin(), 10);
	l.erase(l.begin());
}

void testIterator(){
	list<int> l;
	l.insert(l.begin(), 1);
	l.insert(l.begin(), 2);
	l.insert(l.begin(), 3);

	list<int> itList(l.begin(), l.end());

}

void testCpy(){
	list<int> l;
	l.insert(l.begin(), 3);
	l.insert(l.begin(), 2);
	l.insert(l.begin(), 1);
	list<int> l2(l);//拷贝
	list<int> l3 = l;//赋值
	list<int> l4;
	l4.swap(l3);//交换
}

void testOperator(){
	list<int> l(10, 2);
	list<int> l2 = l;
}

int main(){
	//testInsert();
	//testN_Val();
	//testErase();
	testCpy();//!
	///testIterator();
	//testOperator();
	return 0;
}