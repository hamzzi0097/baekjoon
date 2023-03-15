#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool isZero = false;
bool isOne = false;

int N, M;

queue<pair<int, int>> q;

int tomato[1001][1001] = { 0, };
int depth[1001][1001] = { 0, };

int spread() {
	int cur_c;
	int cur_r;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		cur_r = p.first;
		cur_c = p.second;

		if (cur_c > 0) {
			if (tomato[cur_r][cur_c - 1] == 0) {
				depth[cur_r][cur_c - 1] = depth[cur_r][cur_c] + 1;
				tomato[cur_r][cur_c - 1] = 1;
				q.push({ cur_r,cur_c - 1 });
			}
		}
		if (cur_c < N - 1) {
			if (tomato[cur_r][cur_c + 1] == 0) {
				depth[cur_r][cur_c + 1] = depth[cur_r][cur_c] + 1;
				tomato[cur_r][cur_c + 1] = 1;
				q.push({ cur_r,cur_c + 1 });
			}
		}
		if (cur_r > 0) {
			if (tomato[cur_r - 1][cur_c] == 0) {
				depth[cur_r - 1][cur_c] = depth[cur_r][cur_c] + 1;
				tomato[cur_r - 1][cur_c] = 1;
				q.push({ cur_r - 1, cur_c });
			}
		}
		if (cur_r < M - 1) {
			if (tomato[cur_r + 1][cur_c] == 0) {
				depth[cur_r + 1][cur_c] = depth[cur_r][cur_c] + 1;
				tomato[cur_r + 1][cur_c] = 1;
				q.push({ cur_r + 1,cur_c });
			}
		}
	}
	return depth[cur_r][cur_c];
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		vector<int> v1;
		vector<int> d;
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			tomato[i][j] = num;

			if (num == 1) {
				q.push({ i,j });
			}
		}
	}

	// 토마토가 모두 익어있는 상태인지 확인하기
	for (int i = 0; i < M; i++) {
		int *p0 = find(tomato[i], tomato[i]+N, 0);
		if (p0 != tomato[i]+N) {
			isZero = true;
		}
		
		int *p1 = find(tomato[i], tomato[i]+N, 1);
		if (p1 != tomato[i]+N) {
			isOne = true;
		}
	}

	if (!isZero && isOne) {
		cout << 0;
		return 0;
	}

	int days = spread();

	// 익은 후 확인하기
	for (int i = 0; i < M; i++) {
		int *p0 = find(tomato[i], tomato[i]+N, 0);
		if (p0 != tomato[i]+N) {
			cout << -1;
			return 0;
		}
	}

	cout << days;
	return 0;
}