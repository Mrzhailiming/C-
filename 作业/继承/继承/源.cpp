#include <iostream>
using namespace std;

class Car{
public:
	virtual void fun1(){
		;
	}
	virtual void fun2(){
		;
	}
	virtual void fun3(){
		;
	}
private:
	int a;
	//double a;
};

class Benz:public Car{
public:
	void fun1(){
		cout << "benz" << endl;
	}
	void fun2(){
		cout << "benz" << endl;
	}
	void fun3(){
		cout << "benz" << endl;
	}
	/*void fun4(){
		cout << "benz" << endl;
		}*/
};




int main(){
	Car c;
	Benz a;
	Benz b;
	return 0;
}


//class A
//{
//public:
//	A() :m_iVal(0){ test(); }
//	virtual void func() { std::cout << m_iVal << endl; }
//	void test(){ func(); }
//public:
//	int m_iVal;
//};
//
//class B : public A
//{
//public:
//	B(){ test(); }
//	virtual void func()
//	{
//		++m_iVal;
//		std::cout << m_iVal << endl;
//	}
//};
//
//int main(int argc, char* argv[])
//{
//	A*p = new B;
//	p->test();
//	return 0;
//}