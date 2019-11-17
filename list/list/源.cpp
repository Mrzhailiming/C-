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
template <class T, class ref, class ptr>
class ListIterator{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListIterator<T, ref, ptr> self;

	pNode _node;

	//���캯��
	ListIterator(pNode node)
		:_node(node){

	}

	//ǰ��++  _node = _node.next
	//����++
	//���ص��ǵ���������
	self operator++(){
		return _node = _node->_next;
	}
	self oprator++(int){
		//��������һ��++֮ǰ�ĵ�����
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}



	//--   _node = _node.prev
	//������
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

	//��������
	List(const List<T>& val){
		//����ͷ
		createList();
		for (const auto& e : val){
			PushBack(e);
		}
	}

	//����������
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
	//��ֵ��������� // ���
	List<T>& operator=(List<T> val){
		Swap(_head, val._head);//��������, ����ͷ
		return *this;
	}

	//���� ɾ��
	void PushFront(const T& val);
	void PushBack(const T& val);

	void Insert(iterator pos, const T& val);
	iterator Erase(iterator pos){
		//ͷ�ڵ㲻��ɾ 
	}

	void PopBack();
	void PopFront();

	//�Ƿ�Ϊ��
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

	//���
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