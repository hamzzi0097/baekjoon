#include <iostream>
using namespace std;

int N;
int _time[15];
int _pay[15];
int total = 0;

void next_consult(int index, int total_pay) {
	if (index >= N) {
		total = (total_pay > total) ? (total_pay) : (total);
		return;
	}

	next_consult(index + 1, total_pay);

	int next_index = index + _time[index];

	if (next_index - 1 < N) {
		next_consult(next_index, total_pay + _pay[index]);
	}
	else {
		next_consult(next_index, total_pay);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> _time[i] >> _pay[i];
	}

	next_consult(0, 0);

	cout << total;
}