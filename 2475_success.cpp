#include <iostream>
using namespace std;

int main() {
	int temp;
	int result = 0;

	for (int i = 0; i < 5; i++) {
		cin >> temp;
		result += (temp * temp);
	}

	result = result % 10;

	cout << result;
}