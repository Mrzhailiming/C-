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
		return _pNode != l->_pNode;
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
	typedef ListIterator<T, const T&, const T&> const_iterator;
public:
	///////////////////////////////////////////////////////////////
	// List的构造
	list(){
		CreateHead();
	}
	list(int n, const T& value = T()){

	}
	template <class Iterator>
	list(Iterator first, Iterator last){

	}
	list(const list<T>& l){

	}
	list<T>& operator=(const list<T> l){

	}
	~list(){

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

	}
	bool empty()const{
		return _pHead->_pNext == _pHead;
	}
	////////////////////////////////////////////////////////////
	// List Access
	T& front(){
		return _pHead->_pNext->_val;
	}
	const T& front()const{
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
		insert(--end(), val);
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
		PNode pre = pos._pNode->_pPre;
		PNode next = pos._pNode->_pNext;
		pre->_pNext = next;
		next->_pPre = pre;
		delete pos->_pNode;
		pos->_pNode = nullptr;
		return iterator(next);
	}
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

	}
private:
	void CreateHead(){
		_pHead = new Node();
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
		_pHead->_val = T();
	}
	PNode _pHead;
};

int main(){
	list<int> l;
	l.insert(l.begin(), 1);
	l.insert(l.begin(), 2);
	l.insert(l.begin(), 3);
	l.front();
	return 0;
}