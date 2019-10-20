

//class struct 默认访问权限不同 私有 公有
//
//在类内部, 任何成员都可以访问, 和定义的位置无关

//类的对象所占内存的大小 和结构体类似
//函数保存在代码段
//空的类的对象占 1 字节
class A1 {
public: 
	void f1(){}
private:
	int _a;
};
// 类中仅有成员函数 
class A2 { 
public:   
	void f2() {}
};
// 类中什么都没有---空类 
class A3 {

};
int main () {

	
	return 0;
}