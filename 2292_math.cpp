#include <iostream>
using namespace std;

int N;
int sum = 1;
int cnt = 1;

int main() {
	cin >> N;

	while (1) {
		if (sum >= N) break;
		sum += 6 * cnt;
		cnt++;
	}

	cout << cnt;
}