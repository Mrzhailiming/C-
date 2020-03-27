#include <iostream>
#include <vector>
using namespace std;

template <class K>
struct keyOfValue{
	const K& operator()(K& key){
		return key;
	}
};


template <class V>
class Node{
public:
	typedef Node<V> node;
	typedef node* pNode;
	Node(V& data = V()){
		_data = data;
		_next = nullptr;
	}
	pNode _next;
	V _data;
};

template <class K, class V, class keyOfValue>
class hashBucket{
public:
	typedef Node<V> node;
	typedef node* pNode;
	hashBucket(size_t n = 2){
		_hash.resize(n);
		_size = 0;
	}

	//bool insertNode(V val){
	//	checkCapacity();
	//	keyOfValue kov;
	//	K key = kov(val);
	//	size_t index = key % _hash.size();
	//	pNode cur = _hash[index];
	//	while (cur){
	//		if (kov(cur->_data) == key){
	//			return false;
	//		}
	//		cur = cur->_next;
	//	}
	//	//头插
	//	cur = new node(val);
	//	cur->_next = _hash[index];
	//	_hash[index] = cur;
	//	++_size;
	//	return true;
	//}

	//void checkCapacity(){
	//	if (_size * 2 == _hash.size()){
	//		size_t newC = 2 * _hash.size();
	//		hashBucket<K, V, keyOfValue> newHash(newC);
	//		size_t index = 0;
	//		while (index < _hash.size()){
	//			pNode cur = _hash[index];
	//			while (cur){
	//				pNode next = cur->_next;
	//				int newIndex = kov(cur->_data) % newHash._size();
	//				//头插
	//				cur->_next = newHash._hash[newIndex];
	//				newHash._hash[newIndex] = cur;
	//				cur = next;
	//			}
	//			_hash[index] = nullptr;
	//			++index;
	//		}
	//		_hash.swap(newHash._hash);
	//	}
	//}

	bool insertNode(V val){
		checkCapacity();
		keyOfValue kov;
		size_t index = kov(val) % _hash.size();
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
			size_t newC = _hash.size() * 2;
			hashBucket<K, V, keyOfValue> newHush(newC);
			size_t index = 0;
			while (index < _hash.size()){
				pNode cur = _hash[index];
				keyOfValue kov;
				while (cur){
					pNode next = cur->_next;
					//重新计算位置
					size_t newIndex = kov(cur->_data) % newHush._hash.size();
					//头插
					cur->_next = newHush._hash[newIndex];
					newHush._hash[newIndex] = cur;
					cur = next;
				}
				_hash[index] = nullptr;
				++index;
			}
			_hash.swap(newHush._hash);
		}
	}
	bool eraseNode(K key){
		size_t index = key % _hash.size();
		keyOfValue kov;
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
		while (index < _hash.size()){
			pNode cur = _hash[index];
			while (cur){
				cout << cur->_data << " ";
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

int main(){
	testHushBucket();
	return 0;
}