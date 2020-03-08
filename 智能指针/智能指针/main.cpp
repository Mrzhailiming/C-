#include <iostream>
#include <mutex>
using namespace std;

//auto_ptr
//�ڹ�������ʱ���ȡ��Դ, ��������ʱ���ͷ���Դ
//����a��������b��ʱ��, a�ͷ��Լ�����Դ, ��ȡb����Դ
//b���Լ�ָ����Դ��ָ�븳��,�ᵼ��b�������յ�����
//����* ->
template <class T>
class autoPtr{
public:
	//����
	autoPtr(T* ptr = nullptr)
	:_ptr(ptr){
		;
	}

	//��������
	autoPtr(autoPtr<T>& ap)
	:_ptr(ap._ptr){
		ap._ptr = nullptr;
	}

	//��ֵ���������
	autoPtr<T>& operator=(autoPtr<T>& ap){
		if (this != &ap){
			if (_ptr){
				delete _ptr;
			}
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}

	T& operator*(){
		return *_ptr;
	}

	T* operator->(){
		return _ptr;
	}

	~autoPtr(){
		if (_ptr != nullptr){
			delete _ptr;
			_ptr = nullptr;
		}
	}
private:
	T* _ptr;
};
//
//int main(){
//	autoPtr<int> p = new int(1);
//	autoPtr<int> p1 = p;
//	//*p;
//	return 0;
//}

//shared_ptr
template <class T>
class sharedPtr{
public:
	//���캯��
	sharedPtr(T* ptr = nullptr)
	:_ptr(ptr)
	,_pmt(new mutex)
	,_ptrCount(new int(0)){
		if (_ptr){
			addPtrCount();
		}
		cout << "����->��ǰ���ü���Ϊ :" << *_ptrCount << endl;
	}
	void addPtrCount(){
		(*_pmt).lock();
		++*_ptrCount;
		(*_pmt).unlock();
	}

	//��������
	sharedPtr(sharedPtr<T>& ap)
		:_ptr(ap._ptr)
		, _ptrCount(ap._ptrCount)
		,_pmt(ap._pmt){
		if (ap._ptr)
			addPtrCount();
		cout << "����->��ǰ���ü���Ϊ :" << *_ptrCount << endl;
	}

	//��ֵ���������
	sharedPtr<T>& operator=(sharedPtr<T>& ap){
		//�Ƿ����Լ����Լ���ֵ
		if (this != &ap){
			//���ͷ�ԭ����
			clearCount();
			_ptr = ap._ptr;
			_ptrCount = ap._ptrCount;
			_pmt = ap._pmt;
			if (ap._ptr)
				addPtrCount();
		}
		cout << "��ֵ->��ǰ���ü���Ϊ :" << *_ptrCount << endl;
		return *this;
	}

	//����*
	sharedPtr<T>& operator*(){
		return *_ptr;
	}

	//����->
	sharedPtr<T>* operator->(){
		return _ptr;
	}

	//������Դ
	void clearCount(){
		if (_ptr){
			//��ǰ���������һ��������Դ��
			if (*_ptrCount == 1){
				cout << "ֱ������->��ǰ���ü���Ϊ :" << *_ptrCount << endl;
				delete _ptr;
				_ptr = nullptr;
			}
			else{
				(*_pmt).lock();
				cout << "����ǰ->��ǰ���ü���Ϊ :" << *_ptrCount << endl;
				--*_ptrCount;
				(*_pmt).unlock();
			}
		}
	}

	//��������
	~sharedPtr(){
		clearCount();
	}
private:
	T* _ptr;
	int* _ptrCount;
	mutex* _pmt;//��֤�������ü�����ԭ�Ӳ���
};



//int main(){
//	sharedPtr<int> sp1;//û�й�����Դ
//	sharedPtr<int> sp2(sp1);//û�й�����Դ
//	sharedPtr<int> sp3(new int(10));//���ü���1
//	sp1 = sp3;//���ü���2
//	sp2 = sp3;//���ü���3
//	return 0;
//}

template <class T>
class weakPtr{
public:
	weakPtr(const sharedPtr& shPtr = nullptr)
		:_shPtr(&shPtr){
		;
	}

	//�ṩһ��lock,����ȡshared_ptr
	sharedPtr* Lock(){
		if (*(_shPtr->_ptrCount) > 0){
			return _shPtr;
		}
		else
		{
			return nullptr;
		}
	}
private:
	sharedPtr<T>* _shPtr;
};

int main(){
	
	return 0;
}