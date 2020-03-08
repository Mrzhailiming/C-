#include <iostream>
#include <mutex>
using namespace std;

//auto_ptr
//在构造对象的时候获取资源, 在析构的时候释放资源
//对象a拷贝对象b的时候, a释放自己的资源, 获取b的资源
//b把自己指向资源的指针赋空,会导致b对象悬空的问题
//重载* ->
template <class T>
class autoPtr{
public:
	//构造
	autoPtr(T* ptr = nullptr)
	:_ptr(ptr){
		;
	}

	//拷贝构造
	autoPtr(autoPtr<T>& ap)
	:_ptr(ap._ptr){
		ap._ptr = nullptr;
	}

	//赋值运算符重载
	autoPtr<T>& operator=(autoPtr<T>& ap){
		if (this != &ap){
			if (_ptr){
				delete _ptr;
			}
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}

	T& operator*(){
		return *_ptr;
	}

	T* operator->(){
		return _ptr;
	}

	~autoPtr(){
		if (_ptr != nullptr){
			delete _ptr;
			_ptr = nullptr;
		}
	}
private:
	T* _ptr;
};
//
//int main(){
//	autoPtr<int> p = new int(1);
//	autoPtr<int> p1 = p;
//	//*p;
//	return 0;
//}

//shared_ptr
template <class T>
class sharedPtr{
public:
	//构造函数
	sharedPtr(T* ptr = nullptr)
	:_ptr(ptr)
	,_pmt(new mutex)
	,_ptrCount(new int(0)){
		if (_ptr){
			addPtrCount();
		}
		cout << "构造->当前引用计数为 :" << *_ptrCount << endl;
	}
	void addPtrCount(){
		(*_pmt).lock();
		++*_ptrCount;
		(*_pmt).unlock();
	}

	//拷贝构造
	sharedPtr(sharedPtr<T>& ap)
		:_ptr(ap._ptr)
		, _ptrCount(ap._ptrCount)
		,_pmt(ap._pmt){
		if (ap._ptr)
			addPtrCount();
		cout << "拷贝->当前引用计数为 :" << *_ptrCount << endl;
	}

	//赋值运算符重载
	sharedPtr<T>& operator=(sharedPtr<T>& ap){
		//是否是自己给自己赋值
		if (this != &ap){
			//先释放原来的
			clearCount();
			_ptr = ap._ptr;
			_ptrCount = ap._ptrCount;
			_pmt = ap._pmt;
			if (ap._ptr)
				addPtrCount();
		}
		cout << "赋值->当前引用计数为 :" << *_ptrCount << endl;
		return *this;
	}

	//重载*
	sharedPtr<T>& operator*(){
		return *_ptr;
	}

	//重载->
	sharedPtr<T>* operator->(){
		return _ptr;
	}

	//清理资源
	void clearCount(){
		if (_ptr){
			//当前对象是最后一个管理资源的
			if (*_ptrCount == 1){
				cout << "直接析构->当前引用计数为 :" << *_ptrCount << endl;
				delete _ptr;
				_ptr = nullptr;
			}
			else{
				(*_pmt).lock();
				cout << "析构前->当前引用计数为 :" << *_ptrCount << endl;
				--*_ptrCount;
				(*_pmt).unlock();
			}
		}
	}

	//析构函数
	~sharedPtr(){
		clearCount();
	}
private:
	T* _ptr;
	int* _ptrCount;
	mutex* _pmt;//保证操作引用计数是原子操作
};



//int main(){
//	sharedPtr<int> sp1;//没有管理资源
//	sharedPtr<int> sp2(sp1);//没有管理资源
//	sharedPtr<int> sp3(new int(10));//引用计数1
//	sp1 = sp3;//引用计数2
//	sp2 = sp3;//引用计数3
//	return 0;
//}

template <class T>
class weakPtr{
public:
	weakPtr(const sharedPtr& shPtr = nullptr)
		:_shPtr(&shPtr){
		;
	}

	//提供一个lock,来获取shared_ptr
	sharedPtr* Lock(){
		if (*(_shPtr->_ptrCount) > 0){
			return _shPtr;
		}
		else
		{
			return nullptr;
		}
	}
private:
	sharedPtr<T>* _shPtr;
};

int main(){
	
	return 0;
}