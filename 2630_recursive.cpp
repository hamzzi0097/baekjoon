#include <iostream>
using namespace std;

int N;
int cnt_white = 0;
int cnt_blue = 0;
int arr[129][129];

void checkColor(int x_start, int x_end, int y_start, int y_end) {
	int temp = arr[x_start][y_start];
	bool isSingleColor = true;
	for (int i = x_start; i <= x_end; i++) {
		for (int j = y_start; j <= y_end; j++) {
			if (temp != arr[i][j]) {
				isSingleColor = false;
				i = x_end + 1;
				break;
			}
		}
	}

	if (isSingleColor) {
		if (temp == 0) {
			cnt_white++;
		}
		else {
			cnt_blue++;
		}
	}
	else {
		checkColor(x_start, (x_start + x_end) / 2, y_start, (y_start + y_end) / 2);
		checkColor(x_start, (x_start + x_end) / 2, (y_start + y_end) / 2 + 1, y_end);
		checkColor((x_start + x_end) / 2 + 1, x_end, y_start, (y_start + y_end) / 2);
		checkColor((x_start + x_end) / 2 + 1, x_end, (y_start + y_end) / 2 + 1, y_end);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	checkColor(1, N, 1, N);
	cout << cnt_white << "\n";
	cout << cnt_blue << "\n";
}