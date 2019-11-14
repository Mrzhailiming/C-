#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

template <class T>
class Vector{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	//无参构造, 空间为 0
	Vector()
		:_start(nullptr),
		_finish(nullptr),
		_eos(nullptr){

	}
	void push_back(const T& val){
		////容量
		//if (_finish == _eos){
		//	size_t newc = _start == nullptr ? 1 : 2 * Capacity();
		//	Reserve(newc);
		//}
		////赋值运算符重载, 深拷贝
		//*_finish = val;
		//++_finish;

		Insert(end(), val);
	}

	//容量
	size_t Capacity()const{
		return _eos - _start;
	}

	//重新开辟容量
	void Reserve(size_t n){
		int len = Size();
		if (n > Capacity()){
			//开空间
			T* tmp = new T[n];

			//浅拷贝, 在有资源的时候,会出现二次释放的问题
			//memcpy(tmp, _start, sizeof(T)* Capacity());
			
			//深拷贝
			for (int i = 0; i < len; ++i){
				tmp[i] = _start[i];
			}

			//释放
			delete[] _start;
			_start = tmp;
			_finish = _start + len;
			_eos = _start + n;
		}
	}
	//元素个数
	size_t Size()const{
		return _finish - _start;
	}
	//访问
	T& operator[](size_t pos){
		assert(pos < Size());
		return _start[pos];
	}
	const T& operator[](size_t pos)const{
		assert(pos < Size());
		return _start[pos];
	}

	//插入
	void Insert(iterator pos, const T& val){
		assert(pos >= begin() && pos <= end());
		int len = pos - _start;
		//判断容量
		if (_finish == _eos){
			size_t newc = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newc);
		}
		//如果增容, pos 就会失效
		pos = _start + len;

		//元素移动
		iterator end = _finish;
		while (end > pos){
			*end = *(end - 1);
			--end;
		}
		*end = val;
		++_finish;
	}

	//删除
	iterator Erase(iterator pos){
		assert(pos >= begin() && pos < end());
		iterator begin = pos;
		while (begin < _finish - 1){
			*begin = *(begin + 1);
			++begin;
		}
		--_finish;
		//删除pos位置, 后面值往前补位, 此时pos的指向是删除前pos下一个元素
		return pos;
	}

	void Resize(size_t n, const T& val = T()){
		if (n <= Size()){
			_finish = _start + n;
		}
		else{
			if (n > Capacity()){
				//增容
				Reserve(n);
			}
			//赋值
			while (_finish < _start + n){
				*_finish = val;
				++_finish;
			}
		}
	}
	void PopBack(){
		Erase(end() - 1);
	}
	template <class InputIterator>
	Vector(InputIterator first, InputIterator last){
		while (first != last){
			push_back(*first);
			++first;
		}
	}

	//拷贝构造
	Vector(const Vector<T>& vec)
		: _start(new T[vec.Size()])
		, _finish(_start + vec.Size())
		, _eos(_start + vec.Capacity())
	{
		for (size_t i = 0; i < vec.Size(); ++i){
			_start[i] = vec[i];
		}
		
	}
	//赋值运算符重载
	Vector<T>& operator=(Vector<T> vec){
		Swap(vec);
		return *this;
	}
	void Swap(Vector<T>& vec){
		swap(_start, vec._start);
		swap(_finish, vec._finish);
		swap(_eos, vec._eos);
	}

	//迭代器
	iterator begin(){
		return _start;
	}
	iterator end(){
		return _finish;
	}
	const_iterator begin()const{
		return _start;
	}
	const_iterator end()const{
		return _finish;
	}

private:
	iterator _start;
	iterator _finish;//最后一个元素的下一个位置
	iterator _eos;//空间的最后一个位置
};

template <class T>
void PrintVec(const Vector<T>& vec){

	for (size_t i = 0; i < vec.Size(); ++i){
		cout << vec[i] << " ";
	}
	cout << endl;
}

template <class T>
void PrintfIterator(const Vector<T>& vec){
	Vector<T>::const_iterator vit = vec.begin();
	while (vit != vec.end()){
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
}

template <class T>
void PrintFor(const Vector<T>& vec){
	for (const auto& v : vec){
		cout << v << " ";
	}
	cout << endl;
}


void testInt(){
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	/*Vector<int>::iterator it = v.begin();
	while (it != v.end()){
	if (*it % 2 == 0){
	it = v.Erase(it);
	}
	else
	++it;
	}*/
	//PrintVec(v);

	//Vector<int> v2(v);
	Vector<int> v3;
	v3 = v;
	PrintFor(v);
	PrintFor(v3);
}

void testString(){
	Vector<string> v;
	v.push_back("1");
	v.push_back("2");
	v.push_back("3");
	v.push_back("4");
	v.push_back("5");
	//插入
	v.Insert(v.begin() + 1, "10");

	PrintfIterator(v);

}

void testResize(){
	/*Vector<Vector<int>> v;
	v.push_back(Vector<int>());
	v.push_back(Vector<int>());

	v.Resize(100);
	v.Resize(10);*/
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.Resize(6);
	v.Resize(10, 10);
	v.Resize(2);
}

void testIterator(){
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	Vector<int> v(arr, arr + 6);

	string str("aasajdb");
	Vector<char> v2(str.begin(), str.end());

	Vector<char> v3(v2.begin(), v2.end());
}

int main () {
	//testInt();
	//testString();
	//testResize();
	//testIterator();
	testInt();//拷贝构造

	//
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(1);
	//v.push_back(1);
	//v.push_back(1);
	//auto it = v.begin();
	//v.erase(it);
	////插入删除会导致迭代器失效
	////++it;
	return 0;
}