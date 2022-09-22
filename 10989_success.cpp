#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N;
int num;

int arr[100001] = { 0, };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr[num]++;
	}
}

void output() {
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	output();
}