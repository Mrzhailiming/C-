#include <iostream>
#include <string>
using namespace std;

void fun(int a){
	if (a == 0){
		//�׳��쳣
		throw string("wwwwww");//stringΪ�׳��쳣������
	}
}
int main () {
	int a;
	cin >> a;
	//�����쳣
	try{
		fun(a);
	}
	//�����쳣
	catch (string& str){//�����쳣������
		cout << str << endl;
	}
	catch (...){
		//�����׳�
		throw;
	}
	return 0;
}

