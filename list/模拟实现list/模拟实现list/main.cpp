// List�Ľڵ���
template<class T>
struct ListNode
{
	ListNode(const T& val = T());
	ListNode<T>* _pPre;
	ListNode<T>* _pNext;
	T _val;
};
//List�ĵ�������
template<class T, class Ref, class Ptr>
class ListIterator
{
	typedef ListNode<T>* PNode;
	typedef ListIterator<T, Ref, Ptr> Self;
public:
	ListIterator(PNode pNode = nullptr)��
		ListIterator(const Self& l)��
		T& operator*()��
		T* operator->()��
		Self& operator++()��
		Self operator++(int)��
		Self& operator--();
	Self& operator--(int);
	bool operator!=(const Self& l)��
		bool operator==(const Self& l)��
private:
	PNode _pNode;
};
//list��
template<class T>
class list
{
	typedef ListNode<T> Node;
	typedef Node* PNode;
public:
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&, const T&> const_iterator;
public:
	///////////////////////////////////////////////////////////////
	// List�Ĺ���
	list();
	list(int n, const T& value = T());
	template <class Iterator>
	list(Iterator first, Iterator last);
	list(const list<T>& l);
	list<T>& operator=(const list<T> l);
	~list();
	///////////////////////////////////////////////////////////////
	// List Iterator
	iterator begin();
	iterator end();
	const_iterator begin();
	const_iterator end();
	///////////////////////////////////////////////////////////////
	// List Capacity
	size_t size()const;
	bool empty()const;
	////////////////////////////////////////////////////////////
	// List Access
	T& front();
	const T& front()const;
	T& back();
	const T& back()const;
	////////////////////////////////////////////////////////////
	// List Modify
	void push_back(const T& val){ insert(begin(), val); }
	void pop_back(){ erase(--end()); }
	void push_front(const T& val){ insert(begin(), val); }
	void pop_front(){ erase(begin()); }
	// ��posλ��ǰ����ֵΪval�Ľڵ�
	iterator insert(iterator pos, const T& val);
	// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
	iterator erase(iterator pos);
	void clear();
	void swap(List<T>& l);
private:
	void CreateHead();
	PNode _pHead;
};