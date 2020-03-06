//#include <iostream>
//using namespace std;
//
//template <class T>
//class TreeNode{
//public:
//	TreeNode<T>* _left;
//	TreeNode<T>* _right;
//	TreeNode<T>* _parent;
//	int _fd;
//	T _val;
//	TreeNode(const T& val = T())
//	:_fd(0)
//	,_val(val)
//	,_left(nullptr)
//	,_right(nullptr)
//	,_parent(nullptr){
//		;
//	}
//};
//
//template <class T>
//class AVLTree{
//public:
//	typedef TreeNode<T> Node;
//	typedef Node* pNode;
//	AVLTree(const pNode& root = nullptr)
//		:_root(root){
//		;
//	}
//
//	//插入
//	bool insertNode(const T& val){
//		if (_root == nullptr){
//			//插入为根节点
//			_root = new Node(val);
//		}
//		else{
//			//寻找合适的插入位置
//			pNode cur = _root;
//			pNode parent = cur;
//			while (cur){
//				if (cur->_val == val){
//					return false;
//				}
//				else if(val < cur->_val){
//					parent = cur;
//					cur = cur->_left;
//				}
//				else{
//					parent = cur;
//					cur = cur->_right;
//				}
//			}
//			pNode newNode = new Node(val);
//			if (val < parent->_val){
//				parent->_left = newNode;
//				newNode->_parent = parent;
//			}
//			else{
//				parent->_right = newNode;
//				newNode->_parent = parent;
//			}
//			//插入之后需要更新平衡因子
//			cur = newNode;
//			while (parent){
//				//cur在父节点的左边,则parent平衡因子--
//				if (cur == parent->_left){
//					parent->_fd--;
//				}
//				else{
//					parent->_fd++;
//				}
//				//平衡因子等于0,停止更新
//				if (abs(parent->_fd == 0)){
//					break;
//				}
//				//如果平衡因子为2/-2,跳出
//				if (abs(parent->_fd) == 2){
//					break;
//				}
//				cur = parent;
//				parent = parent->_parent;
//			}
//			//如果平衡因子等于2/-2, 则需要旋转
//			if (parent != NULL && abs(parent->_fd) == 2){
//				//左旋
//				if (parent->_fd == 2 && cur->_fd == 1){
//					Lrotate(parent);
//					parent->_fd = 0;
//					cur->_fd = 0;
//				}
//				//右旋
//				else if (parent->_fd == -2 && cur->_fd == -1){
//					Rrorate(parent);
//				}
//				//先右旋后左旋
//				else if (parent->_fd == 2 && cur->_fd == -1){
//					pNode curLeft = cur->_left;
//					int bf = curLeft->_fd;
//					Rrorate(cur);
//					Lrotate(parent);
//					if (bf == 1){
//						cur->_fd = 0;
//						parent->_fd = -1;
//					}
//					else if(bf == -1){
//						parent->_fd = 0;
//						cur->_fd = 1;
//					}
//				}
//				//先左旋后右旋
//				else if (parent->_fd == -2 && cur->_fd == 1){
//					pNode curRight = cur->_right;
//					int bf = curRight->_fd;
//					Lrotate(cur);
//					Rrorate(parent);
//					if (bf == 1){
//						parent->_fd = 0;
//						cur->_fd = -1;
//					}
//					else if (bf == -1){
//						cur->_fd = 0;
//						parent->_fd = 1;
//					}
//				}
//				else{
//					cout << "parent" << parent->_fd << "cur" << cur->_fd << "旋转出错" << endl;
//				}
//			}
//		}
//		return true;
//	}
//
//	//左旋
//	void Lrotate(pNode parent){
//		//父节点的右节点
//		pNode parentRight = parent->_right;
//		//父节点的右节点的左节点
//		pNode parentRL = parentRight->_left;
//		pNode grandParent = parent->_parent;
//		//把父节点连同左子树全部移动到右节点的左边,右节点原来的左边接到父节点的右边
//
//		//1,2
//		parentRight->_left = parent;
//		parent->_parent = parentRight;
//		//3,4
//		parent->_right = parentRL;
//		if (parentRL != nullptr){
//			//如果parentRL存在
//			parentRL->_parent = parent;
//		}
//		//5,6
//		parentRight->_parent = grandParent;
//		//parent是不是根节点
//		if (parent != _root){
//			//判断原来的parent节点是grand的左还是右节点
//			if (grandParent->_left == parent){
//				grandParent->_left = parentRight;
//			}
//			else{
//				grandParent->_right = parentRight;
//			}
//		}
//		else{
//			_root = parentRight;
//		}
//		parentRight->_fd = parent->_fd = 0;
//	}
//
//	//右旋
//	void Rrorate(pNode parent){
//		pNode grandParent = parent->_parent;
//		pNode parentLeft = parent->_left;
//		pNode parentLeftRight = parentLeft->_right;
//
//		//六个链接
//		parentLeft->_right = parent;
//		parent->_parent = parentLeft;
//
//		parent->_left = parentLeftRight;
//		if (parentLeftRight != nullptr){
//			parentLeftRight->_parent = parent;
//		}
//
//		parentLeft->_parent = grandParent;
//		//parent是不是根节点
//		if (parent != _root){
//			if (grandParent->_left == parent){
//				grandParent->_left = parentLeft;
//			}
//			else{
//				grandParent->_right = parentLeft;
//			}
//		}
//		else{
//			//parent是根节点需要更新_root
//			_root = parentLeft;
//		}
//		//更新平衡因子
//		parentLeft->_fd = parent->_fd = 0;
//	}
//
//	//中序遍历
//	void inOrder(){
//		_inOrder(_root);
//		cout << endl;
//	}
//	void _inOrder(pNode root){
//		if (root){
//			_inOrder(root->_left);
//			cout << root->_val << " ";
//			_inOrder(root->_right);
//		}
//	}
//	int height(pNode root)
//	{
//		if (root == nullptr)
//			return 0;
//		int left = height(root->_left);
//		int right = height(root->_right);
//		return left > right ? left + 1 : right + 1;
//	}
//
//	bool isAVLTree()
//	{
//		if (_isAVLTree(_root)){
//			cout << "yes" << endl;
//			return true;
//		}
//		return false;
//	}
//
//
//	bool _isAVLTree(pNode root)
//	{
//		if (root == nullptr)
//			return true;
//
//		// 1. 平衡因子绝对值小于2
//		// 2. 平衡因子和左右子树的高度差要一致
//		int left = height(root->_left);
//		int right = height(root->_right);
//
//		if (right - left != root->_fd)
//		{
//			cout << "节点：" << root->_val << "平衡因子异常" << endl;
//			return false;
//		}
//
//		return abs(root->_fd) < 2 && _isAVLTree(root->_left) && _isAVLTree(root->_right);
//	}
//private:
//	pNode _root;
//};
//
//
//
////void test(){
////	AVLTree<int> t;
////	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
////	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
////
////	int i = 0;
////	for (; i < 9; ++i){
////		t.insertNode(arr[i]);
////	}
////	t.inOrder();
////	t.isAVLTree();
////}
////
////int main(){
////
////	test();
////
////	return 0;
////}