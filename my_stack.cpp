#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct Stack{
	vector<T> arr;
	int size = 0;
	//Specifications:
	//Requires: None
	//Effects: Returns true if the stack is empty, false otherwise
	bool empty() {
		return size == 0;
	}
	//Specifications:
	//Requires: A value of type T
	//Effects: Adds the value to the stack.
	void push(const T& item) {
		arr.push_back(item);
		size++;
	}
	//Specifications: 
	//Requires: None
	//Effects: Returns the top element of the stack
	T& top() {
		return arr.at(size-1);
	}
	//Specifications:
	//Requires: None
	//Effects: Removes the top element of the stack.
	void pop() {
		if (size != 0) {
			arr.pop_back();
			size--;
		}
	}
};

