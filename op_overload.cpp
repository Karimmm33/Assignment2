#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct Stack {
	vector<T> data;
	int size = 0;


	Stack(vector<T> d = {}, int s = 0) : data(d), size(s) {};

	bool empty() {
		return size == 0;
	}

	void push(const T& item) {
		data.push_back(item);
		size++;
	}

	T& top() {
		return data.at(size - 1);
	}

	void pop() {
		if (size != 0) {
			data.pop_back();
			size--;
		}
	}
	//Please note that the specifications for the above methods 
	// Specifications:
	// Requires: a Stack object
	// Effects: Returns a new stack containing the original stack's items followed by the second stack's items.
	Stack operator +(const Stack& s) {
		int s1 = size + s.size;
		vector<T> result;
		copyStack(result, data);
		copyStack(result, s.data);
		return Stack(result, s1);

	}

	void copyStack(vector<T>& v, const vector<T>& v1) {
		for (int i = 0; i < v1.size(); i++) {
			v.push_back(v1.at(i));
		}
	}
};
int main() {
	Stack <int > a, b;
	a.push(1);
	a.push(2);
	b.push(3);
	b.push(4);
	Stack <int > c = a + b;
	for (int i = 0; i < c.size; i++) {
		cout << c.data.at(i);
	}
}



