#include <iostream>
using namespace std;

long long int x, y;

int main() {
	cin >> x >> y;

	if ((x % 2 == 0) || (y % 2 == 0)) {
		cout << 0;
	}
	else {
		if (x > y) {
			cout << y;
		}
		else {
			cout << x;
		}
	}
}