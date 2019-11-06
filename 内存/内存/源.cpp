#include <iostream>
#include <mutex>
using namespace std;


//ֻ���ڶ��ϴ�������
class Heap{
public:
	//static ����, ͨ����::����, ����.����
	static Heap* getHeap(){
		return new Heap;
	}
private:
	//���캯��˽��
	Heap(){
		cout << "heaponly" << endl;
	}
	//��������ֻ����������,��ֹ����
	Heap(const Heap& h);//C++98
	//Heap(const Heap& h) = delete;//C++11, �����Ѿ���ɾ��, ����ʹ��
};


//ֻ����ջ�ϴ�������
class Stack{

public:
	static Stack getstack(){
		return Stack();
	}
private:

	//���캯��˽�л�
	Stack(){
		cout << "stackonly" << endl;
	}

	//�� ����operator new,ֻ������ʵ��, ��λnewҲ����ʹ��
	void* operator new(size_t n);
	//void* operator new(size_t n) = delete;
	void operator delete(void* p);
};


//����ģʽ:���� ����
class Singleton{
public:
	//���ص�������
	static Singleton* getSingl(){
		return &_instance;
	}
private:
	//���캯��
	Singleton(){}

	//����, ��ֵ, ֻ��������ֵ
	Singleton(const Singleton& s);
	Singleton& operator=(const Singleton& s);

	//���嵥������
	static Singleton _instance;
};
//��ʼ����������
Singleton Singleton::_instance;

//����
//�̰߳�ȫ:˫���
class Singlleton2{
public:
	//���ص���ָ��
	static Singlleton2* getSingl(){
		//double check
		if (p == nullptr){
			_mtx.lock();
			if (p == nullptr){
				p = new Singlleton2;
			}
			_mtx.unlock();
		}
		return p;
	}

	//�ڲ���
	class Gar{
	public:
		~Gar(){
			if (Singlleton2::p){
				delete Singlleton2::p;
				Singlleton2::p = nullptr;
			}
		}
	};
private:
	Singlleton2(){}
	Singlleton2(const Singlleton2& s);

	//�ڲ������
	static Gar g;

	//���嵥��ָ��
	static Singlleton2* p;
	//��
	static mutex _mtx;
};
//��ʼ������ָ��
Singlleton2* Singlleton2::p = nullptr;
//��ʼ����
mutex Singlleton2::_mtx;
//��ʼ���ڲ������
Singlleton2::Gar Singlleton2::g;


int main () {
	//ֻ���ڶ��ϴ���
	//���캯��˽�л�, ��������˽�л�
	//Heap* a = Heap::getHeap();

	//ֻ����ջ�ϴ���
	//���캯��˽��, ʹ��new���ʲ��˹��캯��
	//����new, ʹ��newʹ�ó���
	//Stack* s = new Stack;
	//Stack s = Stack::getstack();


	//���� ����ģʽ
	Singleton* p = Singleton::getSingl();

	Singlleton2* p2 = Singlleton2::getSingl();
	Singlleton2* p3 = Singlleton2::getSingl();
	Singlleton2* p4 = Singlleton2::getSingl();




	return 0;
}