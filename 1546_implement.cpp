#include <iostream>
#include <vector>
using namespace std;

int N;
int score;
int biggest = 0;
float total = 0;
float avg;

vector<float> scores;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> score;
		scores.push_back(score);
		if (biggest < score) {
			biggest = score;
		}
	}

	for (int i = 0; i < scores.size(); i++) {
		total += scores[i] / biggest * 100;
	}

	avg = total / N;

	cout << fixed;
	cout.precision(5);
	cout << avg;
}