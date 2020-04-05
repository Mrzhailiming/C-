#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



//λͼ
class BitMap{
public:
	BitMap(size_t range){
		_range = range / 32 + 1;
		_map.resize(_range);
	}
	void set(size_t num){
		int index = num / 32;
		int position = num % 32;
		_map[index] = _map[index] | (1 << position);
	}
	void reset(size_t num){
		int index = num / 32;
		int position = num % 32;
		_map[index] = _map[index] & ~(1 << position);
	}
	bool find(size_t num){
		int index = num / 32;
		int position = num % 32;
		if ((_map[index] >> position) & 1){
			return true;
		}
		return false;
	}
private:
	vector<int> _map;
	size_t _range;
};


//��¡������:��λͼ�Ļ�����,���Ӷ����ϣ����
//�ж�Ԫ�ش���ʱ, Ԫ�ز�һ������
//�ж�Ԫ�ز�����ʱ, Ԫ��һ��������

//��ϣ����(�÷º���ʵ��)
struct hashFunction1{
	size_t operator()(size_t num){
		size_t tmp = num * 65539;
		return tmp;
	}
};
struct hashFunction2{
	size_t operator()(size_t num){
		size_t tmp = num * 131;
		return tmp;
	}
};
struct hashFunction3{
	size_t operator()(size_t num){
		size_t tmp = num * 13;
		return tmp;
	}
};
template <class hashFun1 = hashFunction1, class hashFun2 = hashFunction2, class hashFun3 = hashFunction3>
class BloomFilter{
public:
	BloomFilter(size_t range)
		:_map(range)
		,_maxNum(range){
	}
	void set(size_t num){
		//��ϣ�������������ֵҪ%λͼ�ܱ�ʾ�����Χ
		size_t index1 = hashFun1()(num) % _maxNum;
		size_t index2 = hashFun2()(num) % _maxNum;
		size_t index3 = hashFun3()(num) % _maxNum;
		_map.set(index1);
		_map.set(index2);
		_map.set(index3);
	}
	bool find(size_t num){
		size_t index1 = hashFun1()(num) % _maxNum;
		size_t index2 = hashFun2()(num) % _maxNum;
		size_t index3 = hashFun3()(num) % _maxNum;
		if (_map.find(index1) == nullptr){
			return false;
		}
		if (_map.find(index2) == nullptr){
			return false;
		}
		if (_map.find(index3) == nullptr){
			return false;
		}
		//num ��һ������
		return true;
	}
private:
	BitMap _map;
	size_t _maxNum;
};

void testBitMap(){
	BitMap mp(300);
	mp.set(0);
	mp.set(32);
	mp.set(64);
	bool ret = mp.find(0);
	ret = mp.find(32);
	ret = mp.find(100);
}

void testBloomFilter(){
	BloomFilter<hashFunction1, hashFunction2,hashFunction3> b(300);
	b.set(0);
	b.set(32);
	b.set(64);

}
int main(){
	//testBitMap();
	testBloomFilter();
	return 0;
}