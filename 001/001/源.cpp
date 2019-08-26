#include <iostream>

class A{
private:
	int x, y;
public:
	A(int a, int b);
	void show(int a, int b){
		x = a;
		y = a;
		printf("%d %d",x,y);
	}
};
int main () {
	class A a(2, 3);
	a.show(2,3);
	return 0;
}