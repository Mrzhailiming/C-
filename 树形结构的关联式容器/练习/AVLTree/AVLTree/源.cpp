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
//	//����
//	bool insertNode(const T& val){
//		if (_root == nullptr){
//			//����Ϊ���ڵ�
//			_root = new Node(val);
//		}
//		else{
//			//Ѱ�Һ��ʵĲ���λ��
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
//			//����֮����Ҫ����ƽ������
//			cur = newNode;
//			while (parent){
//				//cur�ڸ��ڵ�����,��parentƽ������--
//				if (cur == parent->_left){
//					parent->_fd--;
//				}
//				else{
//					parent->_fd++;
//				}
//				//ƽ�����ӵ���0,ֹͣ����
//				if (abs(parent->_fd == 0)){
//					break;
//				}
//				//���ƽ������Ϊ2/-2,����
//				if (abs(parent->_fd) == 2){
//					break;
//				}
//				cur = parent;
//				parent = parent->_parent;
//			}
//			//���ƽ�����ӵ���2/-2, ����Ҫ��ת
//			if (parent != NULL && abs(parent->_fd) == 2){
//				//����
//				if (parent->_fd == 2 && cur->_fd == 1){
//					Lrotate(parent);
//					parent->_fd = 0;
//					cur->_fd = 0;
//				}
//				//����
//				else if (parent->_fd == -2 && cur->_fd == -1){
//					Rrorate(parent);
//				}
//				//������������
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
//				//������������
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
//					cout << "parent" << parent->_fd << "cur" << cur->_fd << "��ת����" << endl;
//				}
//			}
//		}
//		return true;
//	}
//
//	//����
//	void Lrotate(pNode parent){
//		//���ڵ���ҽڵ�
//		pNode parentRight = parent->_right;
//		//���ڵ���ҽڵ����ڵ�
//		pNode parentRL = parentRight->_left;
//		pNode grandParent = parent->_parent;
//		//�Ѹ��ڵ���ͬ������ȫ���ƶ����ҽڵ�����,�ҽڵ�ԭ������߽ӵ����ڵ���ұ�
//
//		//1,2
//		parentRight->_left = parent;
//		parent->_parent = parentRight;
//		//3,4
//		parent->_right = parentRL;
//		if (parentRL != nullptr){
//			//���parentRL����
//			parentRL->_parent = parent;
//		}
//		//5,6
//		parentRight->_parent = grandParent;
//		//parent�ǲ��Ǹ��ڵ�
//		if (parent != _root){
//			//�ж�ԭ����parent�ڵ���grand�������ҽڵ�
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
//	//����
//	void Rrorate(pNode parent){
//		pNode grandParent = parent->_parent;
//		pNode parentLeft = parent->_left;
//		pNode parentLeftRight = parentLeft->_right;
//
//		//��������
//		parentLeft->_right = parent;
//		parent->_parent = parentLeft;
//
//		parent->_left = parentLeftRight;
//		if (parentLeftRight != nullptr){
//			parentLeftRight->_parent = parent;
//		}
//
//		parentLeft->_parent = grandParent;
//		//parent�ǲ��Ǹ��ڵ�
//		if (parent != _root){
//			if (grandParent->_left == parent){
//				grandParent->_left = parentLeft;
//			}
//			else{
//				grandParent->_right = parentLeft;
//			}
//		}
//		else{
//			//parent�Ǹ��ڵ���Ҫ����_root
//			_root = parentLeft;
//		}
//		//����ƽ������
//		parentLeft->_fd = parent->_fd = 0;
//	}
//
//	//�������
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
//		// 1. ƽ�����Ӿ���ֵС��2
//		// 2. ƽ�����Ӻ����������ĸ߶Ȳ�Ҫһ��
//		int left = height(root->_left);
//		int right = height(root->_right);
//
//		if (right - left != root->_fd)
//		{
//			cout << "�ڵ㣺" << root->_val << "ƽ�������쳣" << endl;
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