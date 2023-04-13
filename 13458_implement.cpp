#include <iostream>
using namespace std;

int N, B, C;
int tester_num[1000001];
long long int cnt = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		tester_num[i] = num;
	}

	cin >> B >> C;

	cnt += N;

	for (int i = 0; i < N; i++) {
		tester_num[i] -= B;
		if (tester_num[i] > 0) {
			int tmp = tester_num[i] / C;
			if (tester_num[i] % C == 0) {
				cnt += tmp;
			}
			else {
				cnt += tmp + 1;
			}
		}
	}

	cout << cnt;
}