#include <map>
#include <iostream>
using namespace std;

void testMultimap(){
	multimap<char, int> mp;

	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('b', 10));
	mp.insert(make_pair('b', 10));
	mp.insert(make_pair('c', 10));
	//pair<multimap<char, int>::iterator, multimap<char, int>::iterator> ret;
	auto ret = mp.equal_range('a');
	while (ret.first != ret.second){
		cout << ret.first->first << endl;
		++ret.first;
	}
}


void testmap(){
	map<char, int> mp;

	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('a', 10));
	mp.insert(make_pair('b', 10));
	mp.insert(make_pair('b', 10));
	mp.insert(make_pair('c', 10));
	//pair<multimap<char, int>::iterator, multimap<char, int>::iterator> ret;
	auto ret = mp.equal_range('a');
	while (ret.first != ret.second){
		cout << ret.first->first << endl;
		++ret.first;
	}
}

int main(){
	//testMultimap();
	testmap();


	return 0;
}