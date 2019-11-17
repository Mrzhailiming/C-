//swap(list1, list2) 交换头指针
//1ist.merge(list2) 合并两个有序的  合并之后,list2 为空



//节点
template <class T>
class ListNode{
public:
	T _data;
	ListNode<T>* _prev;
	ListNode<T>* _next;
	ListNode(const T& val = T())
		:_data(val)
		, _prev(nullptr)
		, _next(nullptr){

	}

};

//迭代器
template <class T, class ref, class ptr>
class ListIterator{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, ref, ptr> self;

	pNode _node;

	//构造函数
	ListIterator(pNode node)
		:_node(node){

	}

	//前置++  _node = _node.next
	//后置++
	//返回的是迭代器本身
	self operator++(){
		return _node = _node->_next;
	}
	self oprator++(int){
		//拷贝构造一个++之前的迭代器
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}



	//--   _node = _node.prev
	//解引用
	// ->
	// != _node != itrator._node



};


template <class T>
class List{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T*> const_iterator;

	List(){
		createList();
	}
	void createList(){
		_head = new Node();
		_head->_next = _head;
		_head->_prev = _head;
	}

	//拷贝构造
	List(const List<T>& val){
		//创建头
		createList();
		for (const auto& e : val){
			PushBack(e);
		}
	}

	//迭代器构造
	List(iterator first, iterator end){
		//
		createList();
		while (first != end){
			PushBack(*first);
			++first;
		}
	}

	template <class T>
	void Swap(T& a, T& b){
		T tmp = a;
		a = b;
		b = tmp;
	}
	//赋值运算符重载 // 深拷贝
	List<T>& operator=(List<T> val){
		Swap(_head, val._head);//拷贝构造, 交换头
		return *this;
	}

	//插入 删除
	void PushFront(const T& val);
	void PushBack(const T& val);

	void Insert(iterator pos, const T& val);
	iterator Erase(iterator pos){
		//头节点不能删 
	}

	void PopBack();
	void PopFront();

	//是否为空
	bool Empty(){
		return _head == _head->_next;
	}
	//
	size_t Size(){
		size_t sz = 0;
		for (auto e : _head->_next){
			++sz;
		}
		return sz;
	}

	//清空
	void Clear(){
		if (!Empty()){
			iterator it = begin();
			while (it != end()){
				it = Erase(it);
			}
		}
	}

	~List(){
		Clear();
		if (_head){
			delete _head;
			_head = nullptr;
		}
	}
private:
	pNode _head;
};

int main () {
	List<int> ls;
	return 0;
}