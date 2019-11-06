#include <iostream>
#include <mutex>
using namespace std;


//只能在堆上创建对象
class Heap{
public:
	//static 修饰, 通过类::调用, 对象.调用
	static Heap* getHeap(){
		return new Heap;
	}
private:
	//构造函数私有
	Heap(){
		cout << "heaponly" << endl;
	}
	//拷贝构造只声明不定义,防止拷贝
	Heap(const Heap& h);//C++98
	//Heap(const Heap& h) = delete;//C++11, 函数已经被删除, 不能使用
};


//只能在栈上创建对象
class Stack{

public:
	static Stack getstack(){
		return Stack();
	}
private:

	//构造函数私有化
	Stack(){
		cout << "stackonly" << endl;
	}

	//或 重载operator new,只声明不实现, 定位new也不能使用
	void* operator new(size_t n);
	//void* operator new(size_t n) = delete;
	void operator delete(void* p);
};


//单例模式:饿汉 懒汉
class Singleton{
public:
	//返回单例对象
	static Singleton* getSingl(){
		return &_instance;
	}
private:
	//构造函数
	Singleton(){}

	//拷贝, 赋值, 只声明不赋值
	Singleton(const Singleton& s);
	Singleton& operator=(const Singleton& s);

	//定义单例对象
	static Singleton _instance;
};
//初始化单例对象
Singleton Singleton::_instance;

//饿汉
//线程安全:双检查
class Singlleton2{
public:
	//返回单例指针
	static Singlleton2* getSingl(){
		//double check
		if (p == nullptr){
			_mtx.lock();
			if (p == nullptr){
				p = new Singlleton2;
			}
			_mtx.unlock();
		}
		return p;
	}

	//内部类
	class Gar{
	public:
		~Gar(){
			if (Singlleton2::p){
				delete Singlleton2::p;
				Singlleton2::p = nullptr;
			}
		}
	};
private:
	Singlleton2(){}
	Singlleton2(const Singlleton2& s);

	//内部类对象
	static Gar g;

	//定义单例指针
	static Singlleton2* p;
	//锁
	static mutex _mtx;
};
//初始化单例指针
Singlleton2* Singlleton2::p = nullptr;
//初始化锁
mutex Singlleton2::_mtx;
//初始化内部类对象
Singlleton2::Gar Singlleton2::g;


int main () {
	//只能在堆上创建
	//构造函数私有化, 拷贝构造私有化
	//Heap* a = Heap::getHeap();

	//只能在栈上创建
	//构造函数私有, 使得new访问不了构造函数
	//重载new, 使得new使用出错
	//Stack* s = new Stack;
	//Stack s = Stack::getstack();


	//懒汉 饿汉模式
	Singleton* p = Singleton::getSingl();

	Singlleton2* p2 = Singlleton2::getSingl();
	Singlleton2* p3 = Singlleton2::getSingl();
	Singlleton2* p4 = Singlleton2::getSingl();




	return 0;
}