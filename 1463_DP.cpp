#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int X;
vector<int> v(1000001, 0);

int main() {
	cin >> X;

	for (int i = 2; i <= X; i++) {
		v[i] = v[i - 1] + 1;
		if (i % 3 == 0) {
			v[i] = min(v[i], v[i / 3] + 1);
		}
		if (i % 2 == 0) {
			v[i] = min(v[i], v[i / 2] + 1);
		}
	}

	cout << v[X] << "\n";
}