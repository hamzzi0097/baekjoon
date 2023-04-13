#include <iostream>
using namespace std;

int N;

/*
star가 있으면 0
blank면 1
*/
bool starArr[3000][3000] = { 0, };

/*
star => 0
blank => 1
*/
// blank를 계산
void checkBlank(int s_row, int e_row, int s_col, int e_col) {	
	int n = (e_row - s_row) / 3;

	if (n == 1)return;

	for (int i = s_row + n; i < s_row + n * 2; i++) {
		for (int j = s_col + n; j < s_col + n * 2; j++) {
			starArr[i][j] = 1;
		}
	}

	checkBlank(s_row, s_row + n, s_col, s_col + n);
	checkBlank(s_row, s_row + n, s_col + n, s_col + n * 2);
	checkBlank(s_row, s_row + n, s_col + n * 2, s_col + n * 3);

	checkBlank(s_row + n, s_row + n * 2, s_col, s_col + n);
	checkBlank(s_row + n, s_row + n * 2, s_col + n * 2, s_col + n * 3);

	checkBlank(s_row + n * 2, s_row + n * 3, s_col, s_col + n);
	checkBlank(s_row + n * 2, s_row + n * 3, s_col + n, s_col + n * 2);
	checkBlank(s_row + n * 2, s_row + n * 3, s_col + n * 2, s_col + n * 3);
}

/*
star => 1
blank => 0
*/
// star를 계산
void checkstar(int start_row, int end_row, int start_col, int end_col) {
	if (end_row - start_row == 1 && end_col - start_col == 1) {
		starArr[start_row][start_col] = 1;
		return;
	}

	int n = (end_row - start_row) / 3;

	checkstar(start_row, start_row + n, start_col, start_col + n);
	checkstar(start_row, start_row + n, start_col + n, start_col + n * 2);
	checkstar(start_row, start_row + n, start_col + n * 2, start_col + n * 3);

	checkstar(start_row + n, start_row + n * 2, start_col, start_col + n);
	checkstar(start_row + n, start_row + n * 2, start_col + n * 2, start_col + n * 3);

	checkstar(start_row + n * 2, start_row + n * 3, start_col, start_col + n);
	checkstar(start_row + n * 2, start_row + n * 3, start_col + n, start_col + n * 2);
	checkstar(start_row + n * 2, start_row + n * 3, start_col + n * 2, start_col + n * 3);
}

int main() {
	cin >> N;
	checkstar(0, N, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (starArr[i][j]==1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}