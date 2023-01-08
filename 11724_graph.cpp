#include <iostream>
#include <vector>
using namespace std;

int N, M;
int cnt = 0;
vector<int> vec[1001];

bool isChecked[1001] = { 0, };

void dfs(int num) {
	if (isChecked[num] == 1) return;

	isChecked[num] = 1;
	for (int i = 0; i < vec[num].size(); i++) {
		dfs(vec[num][i]);
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (isChecked[i] == 0) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}