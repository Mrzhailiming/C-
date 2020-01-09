#include <iostream>
using namespace std;

template <class T>
class SmartPtr{
public:
	SmartPtr(T* ptr = nullptr)
	:_ptr(ptr){

	}
	~SmartPtr(){
		if (_ptr){
			free(_ptr);
			cout << "free _ptr" << endl;
		}
		_ptr = nullptr;
	}
	//实现指针的功能
	T& operator*(){
		return *_ptr;
	}
	T* operator->(){
		return _ptr;
	}
private:
	T* _ptr;
};


int main () {
	int* tmp = (int*)malloc(40);
	SmartPtr<int> sp(tmp);
	return 0;
}