#include <iostream>
#include <string.h>
using namespace std;


int main () {
	string s = "hello ";
	string::iterator sit = s.begin();
	//������
	//operator[]
	//��Χfor
	//���ɶ���д
	//while (sit != s.end()){
	//	cout << *sit;
	//	sit++;
	//}

	s.reserve(1);//�����С����
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//s.clear();//��� size = 0; ��������
	//cout << s.capacity() << endl;
	//s.shrink_to_fit();//��С�����ʵ�����
	//cout << s.capacity() << endl;

	//����
	//cout << s[1] << endl;
	//cout<<s.at(1) << endl;

	//�޸�
	//append ����
	//insert ��posλ��ǰ�����
	s.insert(s.begin(), 's');
	while (sit != s.end()){
		cout << *sit;
		sit++;
	}

	s.erase(0, 1);//ɾ������ : ����ҿ�
	//
	string s2("replace");
	s.replace(0, 1, s2);//s2 + ello;

	//����
	cout << s.c_str() << endl;

	//cin �����ո�/���н���
	//getline(cin, ) �������н���

	return 0;
}