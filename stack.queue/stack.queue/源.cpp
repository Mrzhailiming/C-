#include <iostream>
#include <queue>
#include <list>
using namespace std;

//stack: push pop top
//		deque vector list
//		deque deque 增容代价小, 不易造成内存碎片
//queue : push pop front back
//		deque list
//		vector 不支持pop_front
//		deque 增容代价小, 不易造成内存碎片
//	priority_queue : push pop top
//		deque vecter
//		list 不支持随机访问
//		vector 随机访问效率高


//仿函数 重载()
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

//类型萃取
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

//内置类型特化
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