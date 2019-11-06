#include <iostream>
using namespace std;


class Date{
public:
	//Ĭ�Ϲ��캯��
	Date(int year = 2019, int month = 10, int day = 27)
		: _year(year)
		, _month(month)
		, _day(day){
		////�ж����ںϷ���, �Ͳ�ʹ�ò����б�
		//if (month > 12 && month < 1 && day > 31 && day < 1){
		//	//���ڲ��Ϸ�, ��ֵ Ĭ��ֵ
		//	_year = 1;
		//	_day = 1;
		//	_month = 1;
		//}
		//else{
		//	//��ֵ
		//	_year = year;
		//	_day = day;
		//	_month = month;
		//}
	}
	//��������
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day){

	}
	//���� cout cin
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin,Date& d);
	//�õ�ĳ���µ�����
	int getday(int year, int month){
		static int realday[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = realday[month - 1];
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
			day -= 1;
		}
		return day;
	}

	//���������

	Date& operator=(const Date& d){
		//�ж��ǲ�������
		if (this == &d){
			return *this;
		}
		else{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}
	Date operator+=(int days){
		if (days < 0){
			return *this -= (-days);
		}
		_day += days;
		while (_day > getday(_year, _month)){
			_day -= getday(_year, _month);
			++_month;
			if (_month == 13){
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	Date operator-=(int days){
		if (days < 0){
			return *this += (days);
		}
		_day -= days;
		while (_day <= 0){
			--_month;
			if (_month == 0){
				--_year;
				_month = 12;
			}
			_day += getday(_year, _month);
		}
		return *this;
	}

	Date operator+(int days){
		Date tmp = *this;
		return tmp += days;
	}
	Date operator-(int days){
		Date tmp = *this;
		return tmp -= days;
	}

	int operator-(const Date& d);


	//ǰ��++
	Date& operator++(){
		return *this += 1;
	}
	//����++
	Date operator++(int){
		Date tmp = *this;
		*this += 1;
		return tmp;
	}
	Date& operator--(){
		return *this -= 1;
	}
	Date operator--(int){
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}
	bool operator>(const Date& d)const{
		if (_year > d._year){
			return true;
		}
		if (_year == d._year){
			if (_month > d._month){
				return true;
			}
			if (_day > d._day){
				return true;
			}
			return false;
		}
		return false;
	}
	bool operator>=(const Date& d)const{
		if (*this > d){
			return true;
		}
		if (_year == d._year && _month == d._month &&
			_day == _day){
			return true;
		}
		return false;
	}
	bool operator<(const Date& d)const{
		if (*this >= d){
			return false;
		}
		return true;
	}
	bool operator<=(const Date& d)const{
		if (*this > d){
			return false;
		}
		return true;
	}
	bool operator==(const Date& d)const{
		if (!(*this > d) && !(*this < d)){
			return true;
		}
		return false;
	}
	bool operator!=(const Date& d)const{
		if (*this == d){
			return false;
		}
		return true;
	}
	
private:
	int _year;
	int _month;
	int _day;
};


//ostream& operator << (ostream& _cout, const Date& d);
//istream& operator  >> (istream& _cin, Date& d);
//
ostream& operator<<(ostream& _cout, const Date& d){
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Date& d){
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}

int main () {
	Date d;
	cout << d << endl;
	d += 1000;
	cout << d << endl;
	cin >> d;
	cout << d << endl;















	//new delete

	Date* newd = new Date(2019, 1, 11);//new �ķ���ֵ��ָ��

	//new ������, �ײ���� operator new ����, �˺�����װ�� malloc ���캯�� �쳣
	//delete ������, �ײ���� operator delete ����, ������ free ��������

	//��λnew, ԭʼ�ڴ�ռ�
	//Date* p = (Date*)malloc(sizeof(Date));
	//new(p)Date;


	return 0;
}






