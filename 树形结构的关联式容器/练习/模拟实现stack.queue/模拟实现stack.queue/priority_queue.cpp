//#include<vector>
//#include<functional>
//template <class T, class Sequence = vector<T>, class Compare = less<T> >
//class Priority_queue
//{
//public:
//	Priority_queue(){
//		;
//	}
//	//用迭代器构造
//	template <class InputIterator>
//	Priority_queue(InputIterator first, InputIterator last){
//		c(first, last);
//		//堆排序
//		make_heap(c.begin(), c.end(), comp);
//	}
//	bool empty() const{
//		return c.empty();
//	}
//	size_t size() const{
//		return c.size();
//	}
//	T& top() const{
//		if (c.empty() != 1)
//			return c.front();//返回队头元素
//	}
//	void push(const T& x){
//		c.push_back(x);
//		//插入之后排序
//		push_heap(c.begin(), c.end(), comp);
//	}
//	void pop(){
//		pop_heap(c.begin(), c.end(), comp);
//		c.pop_back();
//	}
//private:
//	Sequence c;
//	Compare comp;
//};
//

