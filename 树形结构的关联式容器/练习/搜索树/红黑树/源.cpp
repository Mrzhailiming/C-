#include <iostream>
using namespace std;

template <class T>
class TreeNode{
public:
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	T _val;
	TreeNode(const T& val = T())
		:_val(val),
		_left(nullptr),
		_right(nullptr){
		;
	}
};

template <class T>
class bsTree{
public:
	typedef TreeNode<T> _node;
	typedef _node* pNode;
	bsTree()
		:_root(nullptr){
		;
	}
	//查找
	pNode findNode(const T& val){
		pNode cur = _root;
		while (cur){
			if (cur->_val == val){
				return cur;
			}
			else if (cur->_val > val){
				cur = cur->_left;
			}
			else{
				cur = cur->_right;
			}
		}
		return cur;
	}
	//增加
	bool insertNode(const T& val){
		//第一次插入
		if (_root == nullptr){
			_root = new _node(val);
			return true;
		}
		else{
			pNode cur = _root;
			pNode parent = nullptr;
			while (cur){
				parent = cur;
				if (cur->_val == val){
					return false;
				}
				else if (cur->_val > val){
					cur = cur->_left;
				}
				else{
					cur = cur->_right;
				}
			}
			pNode newNode = new _node(val);
			if (parent->_val < val){
				parent->_right = newNode;
			}
			else{
				parent->_left = newNode;
			}
			return true;
		}
	}

	//删除
	bool eraseNode(const T& val){
		pNode cur = _root;
		pNode parent = nullptr;
		//找到该节点
		while (cur){
			if (cur->_val == val){
				break;
			}
			else if(cur->_val > val){
				parent = cur;
				cur = cur->_left;
			}
			else{
				parent = cur;
				cur = cur->_right;
			}
			
		}
		//没找到
		if (cur == nullptr){
			return false;
		}
		//左子树为空
		else if (cur->_left == nullptr){
			//删除根节点的情况
			if (cur == _root){
				_root = cur->_right;
			}
			//当前节点是父节点的左节点
			else if (parent->_left == cur){
				parent->_left = cur->_right;
			}
			else{
				parent->_right = cur->_right;
			}
			delete cur;
			cur = nullptr;
		}
		//右子树为空
		else if (cur->_right == nullptr){
			//删除根
			if (cur == _root){
				_root = cur->_left;
			}
			//当前节点是父节点的左节点
			else if (parent->_left == cur){
				parent->_left = cur->_left;
			}
			else{
				parent->_right = cur->_left;
			}
			delete cur;
			cur = nullptr;
		}
		//左右子树都存在
		else{
			//寻找左子树的最右节点/右子树的最左节点
			pNode next = cur->_left;
			parent = cur;
			while (next->_right){
				parent = next;
				next = next->_right;
			}
			//左子树没有右节点
			if (parent == cur){
				parent->_left = next->_left;
			}
			else{
				T tmp = cur->_val;
				cur->_val = next->_val;
				next->_val = tmp;
				parent->_right = next->_left;
			}
			delete next;
			next = nullptr;
		}
		return true;
	}

	//中序遍历
	void inOrder(){
		_inOrder(_root);
	}
	void _inOrder(const pNode root){
		if (root){
			_inOrder(root->_left);
			cout << root->_val << "-";
			_inOrder(root->_right);
		}
		
	}
private:
	pNode _root;
};


void test(){
	bsTree<int> t;
	t.insertNode(5);
	t.insertNode(3);
	t.insertNode(7);
	t.insertNode(1);
	t.insertNode(4);
	t.insertNode(6);
	t.insertNode(8);
	t.insertNode(0);
	t.insertNode(2);
	t.insertNode(9);
	t.inOrder();
	cout << endl;

	t.eraseNode(3);
	t.inOrder();
	cout << endl;

	t.eraseNode(5);
	t.inOrder();
	cout << endl;
	/*cout << endl;
	t.eraseNode(8);
	t.inOrder();
	cout << endl;
	t.eraseNode(1);
	t.inOrder();
	cout << endl;
	t.eraseNode(2);
	t.inOrder();
	cout << endl;
	t.eraseNode(4);
	t.inOrder();
	cout << endl;
	t.eraseNode(3);
	t.inOrder();
	cout << endl;
	t.eraseNode(5);
	t.inOrder();
	cout << endl;*/
}

int main(){
	test();
	return 0;
}