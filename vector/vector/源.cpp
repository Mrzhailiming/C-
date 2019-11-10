#include <vector>
#include <iostream>
using namespace std;

int main () {
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	auto it = v.begin();
	v.erase(it);
	++it;

	return 0;
}