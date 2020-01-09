#include <iostream>
using namespace std;
//2020/12/21
//虚表指针
typedef void(*vfptr) ();

class Parent{
public:
	virtual void fun1(){
		cout << "fun1" << endl;
	}
	virtual void fun2(){
		cout << "fun2" << endl;
	}
};
class Child: public Parent{
public:
	virtual void fun1(){
		cout << "Child fun1" << endl;
	}
	virtual void fun2(){
		cout << "fun2" << endl;
	}
};

//打印虚表指向的函数
void PrintfFun(vfptr* p){
	while (*p != nullptr){
		vfptr f = *p;
		f();
		++p;
	}
}

int main () {
	Parent p;
	Child c;
	PrintfFun((vfptr*)(*((int*)&p)));
	PrintfFun((vfptr*)(*((int*)&c)));
	return 0;
}
