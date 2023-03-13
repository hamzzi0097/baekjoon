#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, endTime;
int cnt = 0;
vector<pair<int, int>> v;

bool comp_by_second(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second > p2.second) {
		return false;
	}
	else if (p1.second < p2.second) {
		return true;
	}
	else {
		if (p1.first > p2.first) {
			return false;
		}
		else {
			return true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;

		v.push_back({ start, end });
	}

	sort(v.begin(), v.end(), comp_by_second);

	for (int i = 0; i < N; i++) {
		if (endTime <= v[i].first) {
			endTime = v[i].second;
			cnt++;
		}
	}

	cout << cnt;
}