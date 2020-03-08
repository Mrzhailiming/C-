#include <iostream>

using namespace std;

enum{
	RED,
	BLACK
};

template <class k, class v>
class TreeNode{
public:
	TreeNode(const pair<k, v>& val = pair<k, v>())
		:_val(val)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _color(RED){
		;
	}
	TreeNode<k, v>* _left;
	TreeNode<k, v>* _right;
	TreeNode<k, v>* _parent;
	pair<k, v> _val;
	int _color;
	
};

template <class k, class v>
class RBTree{
public:
	typedef TreeNode<k, v> Node;
	typedef Node* pNode;
	//
	RBTree()
		:_head(new Node()){
		_head->_left = _head;
		_head->_right = _head;
		_head->_parent = nullptr;
	}

	//����
	bool insertNode(pair<k, v>& val){
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
				if (val.first == cur->_val.first){
					return false;
				}
				else if (val.first < cur->_val.first){
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
			if (val.first < parent->_val.first){
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
			cout << root->_val.first << "->" << root->_val.second << "--";
			_inOrder(root->_right);
		}
	}
private:
	TreeNode<k, v>* _head;
};



void test(){
	RBTree<int, int> t;
	t.insertNode(make_pair(1, 1));
	t.insertNode(make_pair(-1, 1));
	t.insertNode(make_pair(2, 1));
	t.insertNode(make_pair(3, 1));
	t.inOrder();
}


int main(){
	test();
	return 0;
}