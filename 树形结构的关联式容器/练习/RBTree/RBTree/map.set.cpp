#if 1
#include <iostream>

using namespace std;

enum{
	RED,
	BLACK
};

//node节点
template <class v>
class TreeNode{
public:
	TreeNode(const v& val = v())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _color(RED){
		;
	}
	TreeNode<v>* _left;
	TreeNode<v>* _right;
	TreeNode<v>* _parent;
	v _val;
	int _color;

};

//封装迭代器
template <class V>
class Itrator{
public:
	typedef Itrator<V> it;
	typedef TreeNode<V> Node;
	typedef Node* pNode;
	Itrator(const pNode val)
		:_root(val){
		;
	}
	V& operator*(){
		return _root->_val;
	}
	V* operator->(){
		return &(_root->_val);
	}
	it& operator++(){
		//当前节点有右节点,则访问右节点的最左节点
		if (_root->_right != nullptr){
			_root = _root->_right;
			while (_root && _root->_left){
				_root = _root->_left;
			}
		}
		//当前节点没有右节点,则判断当前节点是不是父亲的左节点
		else{
			pNode parent = _root->_parent;
			while (_root == parent->_right){
				_root = parent;
				parent = parent->_parent;
			}
			_root = parent;
		}
		return *this;
	}
	bool operator!=(const it& tar){
		return _root != tar._root;
	}

private:
	pNode _root;
};

template <class k, class v, class kOfv>
class RBTree{
public:
	kOfv keyOfvalue;
	typedef TreeNode<v> Node;
	typedef Node* pNode;
	typedef Itrator<v> itrator;//迭代器
	////获取迭代器
	itrator begin(){
		return itrator(_head->_left);
	}
	itrator end(){
		return itrator(_head);
	}
	RBTree()
		:_head(new Node()){
		_head->_left = _head;
		_head->_right = _head;
		_head->_parent = nullptr;
	}
	//查找
	itrator find(const k& key){
		pNode cur = _head->_parent;
		while (cur){
			if (keyOfvalue(cur->_val) == key){
				return itrator(cur);
			}
			else if (key < keyOfvalue(cur->_val)){
				cur = cur->_left;
			}
			else{
				cur = cur->_right;
			}
		}
		return nullptr;
	}

	//插入
	itrator insertNode(v& val){
		//空树的情况
		pNode ret;
		if (_head->_parent == nullptr){
			pNode newNode = new Node(val);
			_head->_parent = newNode;
			_head->_left = newNode;
			_head->_right = newNode;
			//根是黑色的
			newNode->_color = BLACK;
			newNode->_parent = _head;
			return itrator(newNode);
		}
		//不为空树的情况
		
		else{
			//第一步: 寻找合适的插入位置
			pNode cur = _head->_parent;
			pNode parent = nullptr;
			while (cur){
				if (keyOfvalue(val) == keyOfvalue(cur->_val)){
					return itrator(cur);
				}
				else if (keyOfvalue(val) < keyOfvalue(cur->_val)){
					parent = cur;
					cur = cur->_left;
				}
				else{
					parent = cur;
					cur = cur->_right;
				}
			}
			//第二步: 插入
			cur = new Node(val);
			ret = cur;
			cur->_parent = parent;
			if (keyOfvalue(val) < keyOfvalue(parent->_val)){
				parent->_left = cur;
			}
			else{
				parent->_right = cur;
			}
			//第三步: 更新节点颜色, 判断父节点是红的
			while (cur != _head->_parent && parent->_color == RED){
				pNode grandParent = parent->_parent;
				//先判断parent是grandpa的哪边
				//左边
				if (parent == grandParent->_left){
					pNode uncle = grandParent->_right;
					//叔叔节点存在且为红
					if (uncle && uncle->_color == RED){
						parent->_color = BLACK;
						uncle->_color = BLACK;
						grandParent->_color = RED;
						cur = grandParent;
					}
					//叔叔节点不为红或不存在
					else{
						//考虑双旋的情况
						if (cur == parent->_right){
							//先左旋
							leftRotate(parent);
							swap(cur, parent);
						}
						rightRotate(grandParent);
						parent->_color = BLACK;
						grandParent->_color = RED;
						break;//结束更新节点颜色
					}
				}
				//右边
				else{
					pNode uncle = grandParent->_left;
					//如果叔叔节点存在且为红
					if (uncle && uncle->_color == RED){
						uncle->_color = BLACK;
						parent->_color = BLACK;
						grandParent->_color = RED;
					}
					//叔叔节点不存在或不为红, 需要旋转处理
					else{
						//双旋情况
						if (cur == parent->_left){
							rightRotate(parent);
							swap(parent, cur);
						}
						leftRotate(grandParent);
						grandParent->_color = RED;
						parent->_color = BLACK;
						break;//结束更新节点颜色
					}
				}

			}
			//根节点始终黑色
			_head->_parent->_color = BLACK;
			_head->_left = leftNode();
			_head->_right = rightNode();
		}
		return itrator(ret);
	}

	pNode leftNode(){
		pNode cur = _head->_parent;
		while (cur && cur->_left){
			cur = cur->_left;
		}
		return cur;
	}
	pNode rightNode(){
		pNode cur = _head->_parent;
		while (cur && cur->_right){
			cur = cur->_right;
		}
		return cur;
	}
	

	//右旋
	void rightRotate(pNode parent){

		pNode grandParent = parent->_parent;
		pNode parentLeft = parent->_left;
		pNode leftRight = parentLeft->_right;

		//6个连接
		parentLeft->_right = parent;
		parent->_parent = parentLeft;

		parent->_left = leftRight;
		if (leftRight){
			leftRight->_parent = parent;
		}

		parentLeft->_parent = grandParent;
		if (parent != _head->_parent){
			if (grandParent->_left == parent){
				grandParent->_left = parentLeft;
			}
			else{
				grandParent->_right = parentLeft;
			}
		}
		else{
			_head->_parent = parentLeft;
		}
	}

	//左旋
	void leftRotate(pNode parent){
		pNode grandParent = parent->_parent;
		pNode parentRight = parent->_right;
		pNode rightLeft = parentRight->_left;

		parentRight->_left = parent;
		parent->_parent = parentRight;

		parent->_right = rightLeft;
		if (rightLeft){
			rightLeft->_parent = parent;
		}

		parentRight->_parent = grandParent;
		if (parent != _head->_parent){
			if (grandParent->_left == parent){
				grandParent->_left = parentRight;
			}
			else{
				grandParent->_right = parentRight;
			}
		}
		else{
			_head->_parent = parentRight;
		}

	}
	//中序遍历
	void inOrder(){
		_inOrder(_head->_parent);
		cout << endl;
	}
	void _inOrder(pNode root){
		if (root){
			_inOrder(root->_left);
			cout << keyOfvalue(root->_val) << "->" << keyOfvalue(root->_val) << endl;
			_inOrder(root->_right);
		}
	}

	bool isRBTree(){
		if (_head->_parent == nullptr){
			return true;
		}
		//第一步 获取一条路径上的黑色个数
		int totalBlack = 0;
		pNode root = _head->_parent;
		while (root){
			if (root->_color == BLACK){
				++totalBlack;
			}
			root = root->_left;
		}
		int curBlack = 0;
		return _isRBTree(_head->_parent, curBlack, totalBlack);

	}
	bool _isRBTree(pNode root, int curBlack, int totalBlack){
		if (root == nullptr){
			if (curBlack != totalBlack){
				cout << "error black" << endl;
				return false;
			}
			return true;
		}
		pNode parent = root->_parent;
		if (root->_color == RED && parent->_color == RED){
			return false;
		}
		if (root->_color == BLACK){
			++curBlack;
		}
		return _isRBTree(root->_left, curBlack, totalBlack)
			&& _isRBTree(root->_right, curBlack, totalBlack);
	}

	bool empty(){
		if (_head->_parent == _head){
			return true;
		}
		return false;
	}
	void _size(pNode root, int& num){
		if (root == nullptr){
			return;
		}
		++num;
		_size(root->_left, num);
		_size(root->_right, num);
	}
	int size(){
		int num = 0;
		_size(_head->_parent, num);
		return num;
	}

	void _clear(pNode root){
		if (root == nullptr){
			return;
		}
		pNode left = root->_left;
		pNode right = root->_right;
		delete root;
		_clear(left);
		_clear(right);
	}
	void clear(){
		pNode cur = _head->_parent;
		if (cur != _head){
			_clear(cur);
			_head->_left = _head;
			_head->_right = _head;
			_head->_parent = nullptr;
		}
	}
	TreeNode<v>* _head;
	
};



//map
template <class K, class T>
class Map{
public:
	typedef 
	class mapkeyOfvalue{
	public:
		const K& operator()(const pair<K, T>& val){
			return val.first;
		}
	};
	typedef typename RBTree<K, pair<K, T>, mapkeyOfvalue>::itrator it;
	pair<it, bool> insert(pair<K, T>& val){
		it ret = _tree.insertNode(val);
		if (ret != it(_tree._head)){
			return make_pair(ret, true);
		}
		return make_pair(ret, false);
	}
	void inorder(){
		_tree.inOrder();
	}

	//获取迭代器
	
	it begin(){
		return _tree.begin();
	}
	it end(){
		return _tree.end();
	}

	T& operator[](const K& key){
		it ret = Find(key);
		//key存在的情况
		if (ret != nullptr){
			return (*ret).second;
		}
		//key不存在的情况
		else{
			return (*(_tree.insertNode(make_pair(key, 0)))).second;
		}
	}
	it Find(const K& key){
		return _tree.find(key);
	}

	bool Empty(){
		return _tree.empty();
	}
	int Size(){
		return _tree.size();
	}
	void clear(){
		_tree.clear();
	}
private:
	RBTree<K, pair<K, T>, mapkeyOfvalue> _tree;
};

template <class K>
class Set{
public:
	class keyOfvalue{
	public:
		const K& operator()(const K& val = K()){
			return val;
		}
	};
	typedef typename RBTree<K, K, keyOfvalue>::itrator it;
	it insert(const K& val){
		it ret = _tree.insertNode(val);
		if (ret != it(_tree._head)){
			return make_pair(ret, true);
		}
		return make_pair(ret, false);
	}
	int Size(){
		return _tree.size();
	}
	bool Empty(){
		return _tree.empty();
	}
	void Clear(){
		_tree.clear();
	}
	RBTree<K, K, keyOfvalue> _tree;
};




void testFind(){
	Map<int, int> mp;
	mp.insert(make_pair(1, 1));
	mp.insert(make_pair(2, 2));
	mp.insert(make_pair(3, 3));
	mp.insert(make_pair(4, 4));
	mp.insert(make_pair(5, 5));
	mp[10];
	auto ret = mp.insert(make_pair(1, 100));
	mp.inorder();
	int s = mp.Size();
	mp.clear();

}

int main(){
	//test();
	testFind();
	return 0;
}

#endif