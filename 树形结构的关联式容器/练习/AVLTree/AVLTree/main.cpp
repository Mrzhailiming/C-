#include <iostream>
using namespace std;

template <class T>
class TreeNode{
public:
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	TreeNode<T>* _parent;
	int _fd;
	T _val;
	TreeNode(const T& val = T())
		:_fd(0)
		, _val(val)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr){
		;
	}
};

template <class T>
class AVLTree2{
public:
	typedef TreeNode<T> Node;
	typedef Node* pNode;
	AVLTree2(){
		_root = nullptr;
	}
	//右旋
	void rightRorate(pNode parent){

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
		if (parent != _root){
			if (grandParent->_left == parent){
				grandParent->_left = parentLeft;
			}
			else{
				grandParent->_right = parentLeft;
			}
		}
		else{
			_root = parentLeft;
		}

		//更新平衡因子
		parent->_fd = parentLeft->_fd = 0;	
	}

	//左旋
	void leftRorate(pNode parent){
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
		if (parent != _root){
			if (grandParent->_left == parent){
				grandParent->_left = parentRight;
			}
			else{
				grandParent->_right = parentRight;
			}
		}
		else{
			_root = parentRight;
		}

		parentRight->_fd = parent->_fd = 0;
	}

	//插入
	bool insertNode(T& val){
		//空树的情况
		if (_root == nullptr){
			_root = new Node(val);
			return true;
		}
		else{
			//第一步:寻找合适的插入位置
			pNode parent = _root;
			pNode cur = _root;
			while (cur){
				if (cur->_val == val){
					return false;
				}
				else if (val < cur->_val){
					parent = cur;
					cur = cur->_left;
				}
				else{
					parent = cur;
					cur = cur->_right;
				}
			}
			pNode newNode = new Node(val);
			if (val < parent->_val){
				parent->_left = newNode;
			}
			else{
				parent->_right = newNode;
			}
			newNode->_parent = parent;
			//第二步 更新平衡因子
			cur = newNode;
			while (parent){
				if (parent->_left == cur){
					parent->_fd--;
				}
				else{
					parent->_fd++;
				}
				//判断变化后的平衡因子
				if (abs(parent->_fd) == 1){
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_fd == 0){
					break;
				}
				else if (abs(parent->_fd) == 2){
					break;
				}
				else{
					perror("平衡因子变化出错");
				}
			}
			//第三步 平衡因子如果等于 2则进行旋转
			if (parent && abs(parent->_fd) == 2){
				if (parent->_fd == 2 && cur->_fd == 1){
					leftRorate(parent);
				}
				else if (parent->_fd == -2 && cur->_fd == -1){
					rightRorate(parent);
				}
				else if (parent->_fd == 2 && cur->_fd == -1){
					pNode curLeft = cur->_left;
					int fd = curLeft->_fd;
					rightRorate(cur);
					leftRorate(parent);
					if (fd == 1){
						cur->_fd = 0;
						parent->_fd = -1;
					}
					else if (fd == -1){
						parent->_fd = 0;
						cur->_fd = 1;
					}
				}
				else if (parent->_fd == -2 && cur->_fd == 1){
					pNode curRight = cur->_right;
					int fd = curRight->_fd;
					leftRorate(cur);
					rightRorate(parent);
					if (fd == 1){
						cur->_fd = -1;
						parent->_fd = 0;
					}
					else if (fd == -1){
						parent->_fd = 1;
						cur->_fd = 0;
					}
				}
				else{
					cout << "旋转时判断平衡因子出现异常" << endl;
				}
			}
		}
		return true;
	}

	//中序遍历
	void inOrder(){
		_inOrder(_root);
		cout << endl;
	}
	void _inOrder(pNode root){
		if (root){
			_inOrder(root->_left);
			cout << root->_val << " ";
			_inOrder(root->_right);
		}
	}
	
	//求树的最大高度
	int highTree(pNode root){
		if (root == nullptr){
			return 0;
		}
		int left = highTree(root->_left);
		int right = highTree(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	//判断此树是不是avl树
	bool isAVL(){
		if (_isAVL(_root)){
			cout << "is avl tree" << endl;
			return true;
		}
		cout << "is not avl" << endl;
		return false;
	}
	bool _isAVL(pNode root){
		if (root == nullptr){
			return true;
		}
		int left = highTree(root->_left);
		int right = highTree(root->_right);
		if (right - left != root->_fd){
			cout << "error " << root->_val << "出错" << endl;
			return false;
		}
		return abs(right - left) < 2 
			&& _isAVL(root->_left)
			&& _isAVL(root->_right);
	}
private:
	pNode _root;
};


void test(){
	AVLTree2<int> t;
	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	int i = 0;
	for (; i < 9; ++i){
		t.insertNode(arr[i]);
	}
	t.inOrder();
	t.isAVL();
}

int main(){
	test();
	return 0;
}