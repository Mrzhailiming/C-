//stack: push pop top
//		deque vector list
//		deque deque ���ݴ���С, ��������ڴ���Ƭ
//queue : push pop front back
//		deque list
//		vector ��֧��pop_front
//		deque ���ݴ���С, ��������ڴ���Ƭ
//	priority_queue : push pop top
//		deque vecter
//		list ��֧���������
//		vector �������Ч�ʸ�









//�º��� ����()
template <class T>
struct Greater{
	bool operator()(const T& a, const T& b){
		return a > b;
	}
};

template <class T>
struct Less{
	bool operator()(const T& a, const T& b){
		return a < b;
	}
};