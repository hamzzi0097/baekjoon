#include <iostream>
using namespace std;

int T, n;
int arr[11] = { 0,1,2,4 };

/*
* 1 -> 1
* 2 -> 2
* 3 -> 4
* 4 -> 7
*/

int main() {
	for (int i = 4; i < 11; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << arr[n] << "\n";
	}
}