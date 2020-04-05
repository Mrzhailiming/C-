#include <iostream>
#include <vector>
using namespace std;

template <class K>
struct keyOfValue{
	const K& operator()(const K& key){
		return key;
	}
};

//node结点
template <class V>
class Node{
public:
	//node节点
	typedef Node<V> node;
	typedef node* pNode;
	Node(const V& data = V()){
		_data = data;
		_next = nullptr;
	}
	pNode _next;
	V _data;
};

template <class K, class V, class keyOfValue>
class hashBucket;

//迭代器
template <class K, class V, class keyOfValue>
class hashIterator{
public:
	//node节点
	typedef Node<V> node;
	typedef node* pNode;

	//hashBucket
	typedef hashBucket<K, V, keyOfValue> hashBk;
	typedef hashBk* pHashBk;

	//迭代器
	typedef hashIterator<K,V,keyOfValue> Iterator;
	//构造
	hashIterator(pNode pnode, pHashBk phash){
		_node = pnode;
		_hashbucket = phash;
	}
	bool operator==(Iterator& it){
		return _node == it._node;
	}
	bool operator!=(Iterator& it){
		return _node != it._node;
	}
	V& operator*(){
		return _node->_data;
	}
	V* operator->(){
		return &(_node->_data);
	}
	Iterator& operator++(){
		if (_node->_next){
			_node = _node->_next;
		}
		else{
			//借助hashbucket找到下一个位置
			keyOfValue kov;
			int index = kov(_node->_data) % _hashbucket->_hash.size();
			++index;
			while (index < _hashbucket->_hash.size()){
				if (_hashbucket->_hash[index]){
					_node = _hashbucket->_hash[index];
					return *this;
				}
				++index;
			}
			_node = nullptr;
		}
		return *this;
	}


	pNode _node;
	pHashBk _hashbucket;
};




template <class K, class V, class keyOfValue>
class hashBucket{
public:
	//声明迭代器为友元类
	template <class K, class V, class keyOfValue>
	friend class hashIterator;
	
	//迭代器
	typedef hashIterator<K,V,keyOfValue> iterator;
	iterator begin(){
		//寻找第一个有效元素
		size_t index = 0;
		while (index < _hash.size()){
			if (_hash[index]){
				return iterator(_hash[index], this);
			}
			++index;
		}
		return iterator(nullptr, this);
	}
	iterator end(){
		return iterator(nullptr, this);
	}
	//node节点
	typedef Node<V> node;
	typedef node* pNode;

	//仿函数
	typedef keyOfValue keyOf;
	hashBucket(size_t n = 2){
		_hash.resize(n);
		_size = 0;
	}

	bool insertNode(const V& val){
		checkCapacity();
		keyOf kov;
		int index = kov(val) % _hash.size();
		pNode cur = _hash[index];
		while (cur){
			if (kov(cur->_data) == kov(val)){
				return false;
			}
			cur = cur->_next;
		}
		//头插
		cur = new node(val);
		cur->_next = _hash[index];
		_hash[index] = cur;
		++_size;
		return true;
	}

	void checkCapacity(){
		if (_size == _hash.size()){
			size_t newC = 2 * _hash.size();
			vector<pNode> newHash;
			newHash.resize(newC);
			size_t index = 0;
			while (index < _hash.size()){
				pNode cur = _hash[index];
				keyOf kov;
				while (cur){
					pNode next = cur->_next;
					//重新计算位置
					size_t newIndex = kov(cur->_data) % newHash.size();
					//头插
					cur->_next = newHash[newIndex];
					newHash[newIndex] = cur;
					cur = next;
				}
				_hash[index] = nullptr;
				++index;
			}
			_hash.swap(newHash);
		}
	}
	bool eraseNode(const K& key){
		size_t index = key % _hash.size();
		keyOf kov;
		if (_hash[index]){
			pNode cur = _hash[index];
			pNode prev = nullptr;
			while (cur){
				
				//找到
				if (kov(cur->_data) == key){
					//为头结点
					if (cur == _hash[index]){
						_hash[index] = cur->_next;
						delete cur;
						cur = nullptr;
						return true;
					}
					//不为头结点
					else{
						prev->_next = cur->_next;
						delete cur;
						return true;
					}
				}
				prev = cur;
				cur = cur->_next;
			}
		}
		return false;
	}
	void printHash(){
		size_t index = 0;
		keyOf kov;
		while (index < _hash.size()){
			pNode cur = _hash[index];
			while (cur){
				cout << kov(cur->_data) << " ";
				cur = cur->_next;
			}
			++index;
		}
		cout << endl;
	}
private:
	vector<pNode> _hash;
	size_t _size;
};

//map
template <class K, class V>
class hashMap{
public:
	struct MapkeyOfValue{
		const K& operator()(const pair<K, V>& data){
			return data.first;
		}
	};
	bool insert(const pair<K, V>& data){
		return _hashB.insertNode(data);
	}
	bool erase(const K& key){
		return _hashB.eraseNode(key);
	}

	//迭代器
	typedef typename hashBucket<K, pair<K,V>, MapkeyOfValue>::iterator iter;
	iter begin(){
		return _hashB.begin();
	}
	iter end(){
		return _hashB.end();
	}
	void print(){
		_hashB.printHash();
	}
private:
	hashBucket<K, pair<K, V>, MapkeyOfValue> _hashB;
};

//set
template <class K>
class hashSet{
public:
	struct setKeyOfValue{
		const K& operator()(const K& key){
			return key;
		}
	};
	bool insert(const K& data){
		return _hashB.insertNode(data);
	}
	bool erase(const K& key){
		return _hashB.eraseNode(key);
	}
	void print(){
		_hashB.printHash();
	}
private:
	hashBucket<K, K, setKeyOfValue> _hashB;
};


void testHashSet(){
	hashSet<int> hs;
	hs.insert(1);
	hs.insert(2);
	hs.insert(3);
	hs.insert(4);
	hs.insert(5);
	hs.insert(6);
	hs.insert(7);
	hs.insert(17);
	hs.insert(18);
	hs.print();
	hs.erase(17);
	hs.print();
	hs.erase(1);
	hs.print();
}

void testHashMap(){
	hashMap<int, int> hm;
	hm.insert(make_pair(1, 1));
	hm.insert(make_pair(2, 2));
	hm.insert(make_pair(3, 3));
	hm.insert(make_pair(10, 10));
	hm.insert(make_pair(22, 22));
	//hm.print();
	hashMap<int, int>::iter it = hm.begin();
	while (it != hm.end()){

	}
}

void testHushBucket(){
	hashBucket<int, int, keyOfValue<int>> h;
	h.insertNode(1);
	h.insertNode(2);
	h.insertNode(3);
	h.insertNode(4);
	h.insertNode(5);
	h.insertNode(6);
	h.insertNode(9);
	h.insertNode(10);
	h.insertNode(11);
	h.insertNode(12);
	h.insertNode(13);
	h.insertNode(14);
	h.insertNode(17);
	h.insertNode(32);
	h.insertNode(16);
	h.printHash();
	h.eraseNode(9);
	h.printHash();
}

//
//int main(){
//	//testHushBucket();
//	testHashMap();
//	//testHashSet();
//	return 0;
//}