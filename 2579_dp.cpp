#include <iostream>
#include <algorithm>
using namespace std;

int N;
int stairs[301];
int dp[301] = { 0, };

void go_up(int i) {
	if (i > 2) {
		dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
	}
	else if (i == 2) {
		dp[2] = dp[1] + stairs[2];
	}
	else {
		dp[1] = stairs[1];
	}

	if (i == N)
		return;

	go_up(i + 1);
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}

	go_up(1);

	cout << dp[N];
}