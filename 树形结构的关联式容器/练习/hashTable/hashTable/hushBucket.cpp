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
	//	//Í·²å
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
	//				//Í·²å
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
	h.insertNode(77);
	h.insertNode(88);
	h.insertNode(33);
	h.insertNode(44);
	h.insertNode(4);
	h.insertNode(66);
	h.insertNode(6);
	h.insertNode(56);
	h.insertNode(78);
	h.insertNode(22);
	h.printHash();
}

int main(){
	testHushBucket();
	return 0;
}