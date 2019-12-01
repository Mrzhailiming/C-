#include <iostream>
#include <queue>
#include <list>
using namespace std;

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

//������ȡ
struct falseType{
	static bool get(){ return false; }
};
struct trueType{
	static bool get(){ return true; }
};
//
template <class T>
struct typeTraits{
	typedef falseType retType;
};

//���������ػ�
template <>
struct typeTraits<int>{
	typedef trueType retType;
};
template <>
struct typeTraits<char>{
	typedef trueType retType;
};
template <>
struct typeTraits<double>{
	typedef trueType retType;
};

int main () {
	priority_queue<int, list<int>, Greater<int>> s;
 	return 0;
}