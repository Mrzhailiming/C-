#include <iostream>
#include <string>
using namespace std;

void fun(int a)throw(string){//�׳� string ���͵��쳣(��д�������,�Զ�������)
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
		//���ͷ���Դ�������׳��쳣
		//�����׳��쳣
		throw;
	}
	return 0;
}

