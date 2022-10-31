#include <iostream>
using namespace std;

int num;

bool ascending = false;
bool descending = false;

int main() {
	cin >> num;
	if (num == 1) {
		ascending = true;
		for (int i = 2; i < 9; i++) {
			cin >> num;
			if (num != i) {
				ascending = false;
				break;
			}
		}
	}
	if (num == 8) {
		descending = true;
		for (int i = 7; i > 0; i--) {
			cin >> num;
			if (num != i) {
				descending = false;
				break;
			}
		}
	}

	if (ascending) {
		cout << "ascending";
	}
	else if (descending) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}
}