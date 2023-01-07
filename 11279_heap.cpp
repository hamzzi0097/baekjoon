#include <iostream>
#include <queue>
using namespace std;

int N;

priority_queue<int> pq;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		if (temp == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(temp);
		}
	}
}