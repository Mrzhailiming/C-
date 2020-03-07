#include <iostream>
#include <mutex>

using namespace std;


template <class T>
class autoPtr{
public:
	autoPtr(const T* ptr = nullptr)
	:_ptr(ptr){
		;
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


int main(){
	
	return 0;
}

