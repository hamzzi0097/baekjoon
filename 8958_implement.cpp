#include <iostream>
using namespace std;

int N;
int score = 1;
int total = 0;
string ox;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		score = 1;
		total = 0;
		cin >> ox;
		for (int j = 0; j < ox.size(); j++) {
			if (ox[j] == 'O') {
				total += score;
				score++;
			}
			else {
				score = 1;
			}
		}
		cout << total << "\n";
	}
}