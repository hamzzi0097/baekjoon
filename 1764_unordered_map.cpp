#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int cnt = 0;

unordered_map<string, int> not_lis;
vector<string> not_lis_seen;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		not_lis.insert({ name,i });
	}

	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;
		
		if (not_lis.find(name) != not_lis.end()) {
			cnt++;
			not_lis_seen.push_back(name);
		}
	}

	cout << cnt << "\n";

	sort(not_lis_seen.begin(), not_lis_seen.end());

	for (int i = 0; i < not_lis_seen.size(); i++) {
		cout << not_lis_seen[i] << "\n";
	}
}