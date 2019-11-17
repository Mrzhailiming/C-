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
template <class T>
class ListIterator{
	typedef ListNode<T>* pNode;


};


template <class T>
class List{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator iterator;

	List(){
		createList();
	}
	void createList(){
		_head = new Node();
		_head->_next = _head;
		_head->_prev = _head;
	}


private:
	pNode _head;
};

int main () {
	List<int> ls;
	return 0;
}