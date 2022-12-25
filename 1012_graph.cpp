#include <iostream>
#include <vector>
using namespace std;

int T, M, N, K;
int x, y;
int cnt = 0;
int isCabbage[51][51] = { 0, };
int location[2500][2];

void dms(int x, int y) {
	if (!isCabbage[x][y]) return;

	isCabbage[x][y] = 0;
	dms(x + 1, y);
	dms(x - 1, y);
	dms(x, y + 1);
	dms(x, y - 1);
	return;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		cnt = 0;
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			location[j][0] = x;
			location[j][1] = y;
			isCabbage[x][y] = 1;
		}
		for (int j = 0; j < K; j++) {
			if (isCabbage[location[j][0]][location[j][1]]) {
				cnt++;
				dms(location[j][0], location[j][1]);
			}
		}
		cout << cnt << "\n";
	}
}