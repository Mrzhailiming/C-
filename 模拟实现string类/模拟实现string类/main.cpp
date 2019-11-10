#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

class String{
public:

	typedef char* iterator;
	typedef const char* const_iterator;


	//���캯��
	String(char* s = ""){
		_size = strlen(s);
		_str = new char[_size + 1];
		strcpy(_str, s);
		_capacity = _size;
	}
	//��������
	String(const String& str)
	:_str(nullptr),
	_size(0),
	_capacity(0){
		/*char* tmp = new char[sizeof(strlen(str._str)) + 1];
		strcpy(tmp, str._str);*/
		String tmp(str._str);
		Swap(tmp);
	}

	void Swap(String& str){
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	//����
	~String(){
		if (_str){
			delete[] _str;
			_capacity = 0;
			_size = 0;
		}
	}

	String& operator=(String str){
		Swap(str);
		return *this;
	}

	//����
	char& operator[](size_t pos){
		assert(pos < _size);
		return _str[pos];
	}
	const char& operator[](size_t pos) const{
		assert(pos < _size);
		return _str[pos];
	}

	//������
	iterator begin(){
		return _str;
	}
	iterator end(){
		return _str + _size;
	}
	const_iterator begin()const{
		return _str;
	}
	const_iterator end()const{
		return _str + _size;
	}

	//����
	size_t size(){
		return _size;
	}
	//�����޸�capacity��С
	void reserve(size_t newC){
		if (newC > _capacity){
			char* newstr = new char[newC + 1];
			strcpy(newstr, _str);
			delete _str;
			_str = newstr;
			_capacity = newC;
		}
	}
	void resize(size_t n, char c = '\0'){
		if (n > _capacity){
			reserve(n);
		}
		if (n > _size){
			memset(_str + _size, c, n - _size);
		}
		_size = n;
		_str[_size] = '\0';
	}


	//�����ַ�
	void push_back(char c){
		if (_size = _capacity){
			size_t newC = _capacity ? 2 * _capacity : 15;
			reserve(newC);
		}
		_str[_size] = c;
		++_size;
		_str[_size] = '\0';
	}
	//�����ַ���
	void append(const char* str){
		int size = strlen(str);
		if (size + _size > _capacity){
			reserve(size + _size);
		}
		strcpy(_str + _size, str);
		_size += size;
	}

	//+= ���������
	String& operator+=(char c){
		push_back(c);
		return *this;
	}
	String& operator+=(const char* str){
		append(str);
		return *this;
	}
	String& operator+=(const String& str){
		append(str._str);
		return *this;
	}
	//�����ַ�
	void insert(size_t pos, char c){
		assert(pos <= _size);
		//��������
		if (_size == _capacity){
			int newC = _capacity ? 2 * _capacity : 15;
			reserve(newC);
		}
		//�ƶ�Ԫ�� ע�� pos == 0 ʱ����ѭ��
		size_t end = _size + 1;
		while (end >= pos){
			_str[end] = _str[end - 1];
			--end;
		}
		//����
		_str[pos] = c;
		++_size;
	}
	//�����ַ���
	void insert(size_t pos, const char* str){
		int len = strlen(str);
		if (_size + len > _capacity){
			reserve(_size + len);
		}
		size_t end = _size + len;
		while (end >= pos + len - 1){
			_str[end] = _str[end - len];
			--end;
		}
		int i = 0;
		while (*str){
			_str[pos + i] = *str++;
			++i;
		}
		_size += len;
	}
	//ɾ��
	void erase(size_t pos, int len){
		assert(pos < _size);
		if (pos + len >= _size){
			_str[pos] = '\0';
			_size = pos;
		}
		else{
			size_t start = pos + len;
			while (start <= _size){
				_str[start - len] = _str[start];
				++start;
			}
			_size -= len;
		}
	}

	void erase(iterator it){
		assert(it < end() && it >= begin());
		while (it != end()){
			*it = *(it + 1);
			++it;
		}
		--_size;
	}










	friend ostream& operator<<(ostream& _cout, const String& str);



private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

ostream& operator<<(ostream& _cout, const String& str){
	for (const auto& ch : str){
		_cout << ch << ' ';

	}
	return _cout;
}

void test1(){
	String s("123456789");
	s.erase(7, 2);
	s.erase(0, 1);
	s.erase(s.begin());
}


int main(){
	String str("he");
	for (const auto& ch : str){
		cout << ch << " ";
	}
	str += 'v';
	cout << str;
	test1();
	return 0;
}