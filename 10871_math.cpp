#include <iostream>
#include <vector>
using namespace std;

int N, X;
int num;
vector<int> vec;

int main() {
	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num < X) {
			cout << num << " ";
		}
	}
}