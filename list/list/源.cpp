//swap(list1, list2) ����ͷָ��
//1ist.merge(list2) �ϲ����������  �ϲ�֮��,list2 Ϊ��



//�ڵ�
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

//������
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