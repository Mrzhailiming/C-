#include <iostream>
#include <stireg.h>
using namespace std;

class String{
public:
	//构造函数
	String(char* s = "")
		: _str(new char[1]){

	}
	//拷贝构造
	String(const String& str){
		char* tmp = new char[sizeof(strlen(str._str)) + 1];
		strcpy(tmp, str._str);
	}
	//析构
	~String(){
		if (_str){
			delete[] _str;
		}
	}
private:
	char* _str;
};

int main(){

	return 0;
}