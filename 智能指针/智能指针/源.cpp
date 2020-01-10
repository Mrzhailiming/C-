#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
//
//template <class T>
//class SmartPtr{
//public:
//	SmartPtr(T* ptr = nullptr)
//	:_ptr(ptr){
//
//	}
//	~SmartPtr(){
//		if (_ptr){
//			free(_ptr);
//			cout << "free _ptr" << endl;
//		}
//		_ptr = nullptr;
//	}
//	//实现指针的功能
//	T& operator*(){
//		return *_ptr;
//	}
//	T* operator->(){
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//
//int main () {
//	int* tmp = (int*)malloc(40);
//	SmartPtr<int> sp(tmp);
//	return 0;
//}

template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}
	~SharedPtr() {
		Release(); 
	}
	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}
	// sp1 = sp2
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		//if (this != &sp)
		if (_ptr != sp._ptr)
		{
			// 释放管理的旧资源
			Release();
			// 共享管理新对象的资源，并增加引用计数
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

			AddRefCount();
		}
		return *this;
	}
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }
	int UseCount() { return *_pRefCount; }
	T* Get() { return _ptr; }
	void AddRefCount()
	{
		// 加锁或者使用加1的原子操作
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
private:
	void Release()
	{
		bool deleteflag = false;
		/*比特科技
			std::shared_ptr的线程安全问题
			通过下面的程序我们来测试shared_ptr的线程安全问题。需要注意的是shared_ptr的线程安全分为两方面：
			1. 智能指针对象中引用计数是多个智能指针对象共享的，两个线程中智能指针的引用计数同时++或--，这
			个操作不是原子的，引用计数原来是1，++了两次，可能还是2.这样引用计数就错乱了。会导致资源未
			释放或者程序崩溃的问题。所以只能指针中引用计数++、--是需要加锁的，也就是说引用计数的操作是
			线程安全的。
			2. 智能指针管理的对象存放在堆上，两个线程中同时去访问，会导致线程安全问题。
			*/
			// 引用计数减1，如果减到0，则释放资源
		_pMutex.lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		_pMutex.unlock();

		if (deleteflag == true)
			delete _pMutex;
	}
private:
	int* _pRefCount; // 引用计数
	T* _ptr; // 指向管理资源的指针 
	mutex* _pMutex; // 互斥锁
};
int main()
{
	SharedPtr<int> sp1(new int(10));
	SharedPtr<int> sp2(sp1);
	*sp2 = 20;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	SharedPtr<int> sp3(new int(10));
	sp2 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	sp1 = sp3;
	cout << sp1.UseCount() << endl;
	cout << sp2.UseCount() << endl;
	cout << sp3.UseCount() << endl;
	return 0;
}