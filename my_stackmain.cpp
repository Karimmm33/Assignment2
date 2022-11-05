#include <iostream>
#include <vector>
using namespace std;
int main() {
	Stack <int > a;
	a.push(1);
	a.push(2);
  a.pop();
  cout << a.top();
  cout << a.empty();
	}
