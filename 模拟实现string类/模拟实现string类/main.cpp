#include <iostream>
#include <stireg.h>
using namespace std;

class String{
public:
	//���캯��
	String(char* s = "")
		: _str(new char[1]){

	}
	//��������
	String(const String& str){
		char* tmp = new char[sizeof(strlen(str._str)) + 1];
		strcpy(tmp, str._str);
	}
	//����
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