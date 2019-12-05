#include <iostream>
using namespace std;


void YesNo(double lenth, double width){
	if (lenth > width * 3.14){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
	}



}

int main(){
	double lenth, width;
	while (cin >> lenth >> width){
		YesNo(lenth, width);
	}
	return 0;
}