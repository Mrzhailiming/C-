#if 1
#include <iostream>

using namespace std;

enum{
	RED,
	BLACK
};

//node�ڵ�
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

//��װ������
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
		//��ǰ�ڵ����ҽڵ�,������ҽڵ������ڵ�
		if (_root->_right != nullptr){
			_root = _root->_right;
			while (_root && _root->_left){
				_root = _root->_left;
			}
		}
		//��ǰ�ڵ�û���ҽڵ�,���жϵ�ǰ�ڵ��ǲ��Ǹ��׵���ڵ�
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
	typedef Itrator<v> itrator;//������
	////��ȡ������
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

	//����
	bool insertNode(v& val){
		//���������
		if (_head->_parent == nullptr){
			pNode newNode = new Node(val);
			_head->_parent = newNode;
			_head->_left = newNode;
			_head->_right = newNode;
			//���Ǻ�ɫ��
			newNode->_color = BLACK;
			newNode->_parent = _head;
			return true;
		}
		//��Ϊ���������
		else{
			//��һ��: Ѱ�Һ��ʵĲ���λ��
			pNode cur = _head->_parent;
			pNode parent = nullptr;
			while (cur){
				if (keyOfvalue(val) == keyOfvalue(cur->_val)){
					return false;
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
			//�ڶ���: ����
			cur = new Node(val);
			cur->_parent = parent;
			if (keyOfvalue(val) < keyOfvalue(parent->_val)){
				parent->_left = cur;
			}
			else{
				parent->_right = cur;
			}
			//������: ���½ڵ���ɫ, �жϸ��ڵ��Ǻ��
			while (cur != _head->_parent && parent->_color == RED){
				pNode grandParent = parent->_parent;
				//���ж�parent��grandpa���ı�
				//���
				if (parent == grandParent->_left){
					pNode uncle = grandParent->_right;
					//����ڵ������Ϊ��
					if (uncle && uncle->_color == RED){
						parent->_color = BLACK;
						uncle->_color = BLACK;
						grandParent->_color = RED;
						cur = grandParent;
					}
					//����ڵ㲻Ϊ��򲻴���
					else{
						//����˫�������
						if (cur == parent->_right){
							//������
							leftRotate(parent);
							swap(cur, parent);
						}
						rightRotate(grandParent);
						parent->_color = BLACK;
						grandParent->_color = RED;
						break;//�������½ڵ���ɫ
					}
				}
				//�ұ�
				else{
					pNode uncle = grandParent->_left;
					//�������ڵ������Ϊ��
					if (uncle && uncle->_color == RED){
						uncle->_color = BLACK;
						parent->_color = BLACK;
						grandParent->_color = RED;
					}
					//����ڵ㲻���ڻ�Ϊ��, ��Ҫ��ת����
					else{
						//˫�����
						if (cur == parent->_left){
							rightRotate(parent);
							swap(parent, cur);
						}
						leftRotate(grandParent);
						grandParent->_color = RED;
						parent->_color = BLACK;
						break;//�������½ڵ���ɫ
					}
				}

			}
			//���ڵ�ʼ�պ�ɫ
			_head->_parent->_color = BLACK;
			_head->_left = leftNode();
			_head->_right = rightNode();
		}
		return true;
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
	//����
	void rightRotate(pNode parent){

		pNode grandParent = parent->_parent;
		pNode parentLeft = parent->_left;
		pNode leftRight = parentLeft->_right;

		//6������
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

	//����
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
	//�������
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
		//��һ�� ��ȡһ��·���ϵĺ�ɫ����
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
	
private:
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

	bool insert(pair<K, T>& val){
		return _tree.insertNode(val);
	}
	void inorder(){
		_tree.inOrder();
	}

	//��ȡ������
	typedef typename RBTree<K, pair<K, T>, mapkeyOfvalue>::itrator it;
	it begin(){
		return _tree.begin();
	}
	it end(){
		return _tree.end();
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
	bool insert(const K& val){
		return _tree.insertNode(val);
	}

	RBTree<K, K, keyOfvalue> _tree;
};


void test(){
	Map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(3, 3));
	m.insert(make_pair(4, 4));
	m.insert(make_pair(5, 5));
	m.inorder();
	auto it = m.begin();
	while (it != m.end()){
		cout << it->first << endl;
		++it;
	}
}

int main(){
	test();
	return 0;
}

#endif