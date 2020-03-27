//#include <iostream>
//#include <vector>
//#include <utility>
//using namespace std;
//enum{
//	EMPTY,
//	DELETE,
//	EXIST
//};
//
//template <class K, class V>
//struct Node{
//	pair<K, V> _val;
//	int _stat;
//};
//
//template <class K, class V>
//class hashTable{
//public:
//	typedef Node<K, V> Node;
//	typedef Node* pNode;
//	hashTable(size_t size = 2){
//		_hash.resize(size);
//		_size = 0;
//		size_t i = 0;
//		for (; i < size; ++i){
//			_hash[i]._stat = EMPTY;
//		}
//	}
//
//	//bool insertNode(pair<K, V> val){
//	//	//检查容量
//	//	checkCapacity();
//	//	int index = val.first % _hash.size();
//	//	//寻找第一个不为EXIST的位置
//	//	while (_hash[index]._stat == EXIST){
//	//		if (_hash[index]._val.first == val.first){
//	//			return false;
//	//		}
//	//		++index;
//	//		if (index == _hash.size()){
//	//			index = 0;
//	//		}
//	//	}
//	//	_hash[index]._val = val;
//	//	_hash[index]._stat = EXIST;
//	//	_size++;
//	//	return true;
//	//}
//	//void checkCapacity(){
//	//	if (_size * 10 / _hash.size() >= 7){
//	//		size_t newC = 2 * _hash.size();
//	//		hashTable<K, V> nHash(newC);
//	//		size_t i = 0;
//	//		while (i < _hash.size()){
//	//			if (_hash[i]._stat == EXIST){
//	//				nHash.insertNode(_hash[i]._val);
//	//			}
//	//			++i;
//	//		}
//	//		_hash.swap(nHash._hash);
//	//	}
//	//}
//	bool insertNode(pair<K,V>& val){
//		checkCapacity();
//
//		int index = val.first % _hash.size();
//		while (_hash[index]._stat == EXIST){
//			if (_hash[index]._val.first == val.first){
//				//key相同.插入失败
//				return 0;
//			}
//			++index;
//			if (index == _hash.size())
//				index = 0;
//		}
//		//找到合适的位置
//		_hash[index]._val = val;
//		_hash[index]._stat = EXIST;
//		++_size;
//		return true;
//	}
//
//	void checkCapacity(){
//		if (_size * 10 / _hash.size() > 7){
//			size_t newC = 2 * _hash.size();
//			hashTable<K, V> newHush(newC);
//			size_t index = 0;
//			while (index < _hash.size()){
//				if (_hash[index]._stat == EXIST){
//					newHush.insertNode(_hash[index]._val);
//				}
//				++index;
//			}
//			_hash.swap(newHush._hash);
//		}
//	}
//	bool eraseNode(K key){
//		pNode p = findNode(key);
//		if (p){
//			p->_stat = DELETE;
//			--_size;
//			return true;
//		}
//		return false;
//	}
//	pNode findNode(K key){
//		size_t index = key % _hash.size();
//		//
//		while (_hash[index]._stat != EMPTY){
//			if (_hash[index]._stat == EXIST && _hash[index]._val.first == key){
//				return &_hash[index];
//			}
//			++index;
//			//index可能会越界
//			if (index == _hash.size())
//				index = 0;
//		}
//		return nullptr;
//	}
//	void printHash(){
//		for (auto val : _hash){
//			if (val._stat == EXIST)
//				cout << val._val.first << ":" << val._val.second << " ";
//		}
//		cout << endl;
//	}
//private:
//	vector<Node> _hash;
//	size_t _size;
//};
//
//void testInsertNode(){
//	hashTable<int, int> h;
//	h.insertNode(make_pair(1, 1));
//	h.insertNode(make_pair(3, 1));
//	h.insertNode(make_pair(4, 1));
//	h.insertNode(make_pair(5, 1));
//	h.insertNode(make_pair(6, 1));
//	h.insertNode(make_pair(73, 1));
//	h.insertNode(make_pair(81, 1));
//	h.insertNode(make_pair(9, 1));
//	h.printHash();
//	h.eraseNode(73);
//	h.printHash();
//}
//
////int main(){
////	testInsertNode();
////	return 0;
////}