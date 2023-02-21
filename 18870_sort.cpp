#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> origin_vec;
vector<int> sort_vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		origin_vec.push_back(num);
		sort_vec.push_back(num);
	}

	sort(sort_vec.begin(), sort_vec.end());
	sort_vec.erase(unique(sort_vec.begin(), sort_vec.end()), sort_vec.end());

	for (int i = 0; i < N; i++) {
		cout << lower_bound(sort_vec.begin(), sort_vec.end(), origin_vec[i]) - sort_vec.begin() << " ";
	}
}