#include <iostream>
using namespace std;

int N;
int starArr[10000][10000] = { 0, };

void checkStar(int start_row, int end_row, int start_col, int end_col) {
	if (end_row - start_row == 1 && end_col - start_col == 1) {
		starArr[start_row][start_col] = 1;
		return;
	}

	checkStar(start_row, start_row + end_row / 3, start_col, start_col + end_col / 3);
	checkStar(start_row, start_row + end_row / 3, start_col + end_col / 3, start_col + end_col / 3 * 2);
	checkStar(start_row, start_row + end_row / 3, start_col + end_col / 3 * 2, start_col + end_col);
	
	checkStar(start_row + end_row / 3, start_row + end_row / 3 * 2, start_col, start_col + end_col / 3);
	//checkStar(end_row / 3, end_row / 3 * 2, end_col / 3, end_col / 3 * 2);
	checkStar(start_row + end_row / 3, start_row + end_row / 3 * 2, start_col + end_col / 3 * 2, start_col + end_col);
	
	checkStar(start_row + end_row / 3 * 2, start_row + end_row, start_col, start_col + end_col / 3);
	checkStar(start_row + end_row / 3 * 2, start_row + end_row, start_col + end_col / 3, start_col + end_col / 3 * 2);
	checkStar(start_row + end_row / 3 * 2, start_row + end_row, start_col + end_col / 3 * 2, start_col + end_col);
}

int main() {
	cin >> N;
	checkStar(0, N, 0,N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << starArr[i][j] << " ";
			//if (starArr[i][j]==1) {
			//	cout << "*";
			//}
			//else {
			//	cout << " ";
			//}
		}
		cout << "\n";
	}
}