#include <iostream>
#include <string.h>
using namespace std;


int main () {
	string s = "hello ";
	string::iterator sit = s.begin();
	//迭代器
	//operator[]
	//范围for
	//都可读可写
	//while (sit != s.end()){
	//	cout << *sit;
	//	sit++;
	//}

	s.reserve(1);//不会减小容量
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//s.clear();//清空 size = 0; 容量不变
	//cout << s.capacity() << endl;
	//s.shrink_to_fit();//缩小到合适的容量
	//cout << s.capacity() << endl;

	//遍历
	//cout << s[1] << endl;
	//cout<<s.at(1) << endl;

	//修改
	//append 插入
	//insert 在pos位置前面插入
	s.insert(s.begin(), 's');
	while (sit != s.end()){
		cout << *sit;
		sit++;
	}

	s.erase(0, 1);//删除区间 : 左闭右开
	//
	string s2("replace");
	s.replace(0, 1, s2);//s2 + ello;

	//返回
	cout << s.c_str() << endl;

	//cin 遇到空格/换行结束
	//getline(cin, ) 遇到换行结束

	return 0;
}