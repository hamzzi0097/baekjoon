#include <iostream>
using namespace std;

int is_self_number[10001] = { 0, };

int main() {
	for (int i = 1; i < 10001; i++) {
		if (!is_self_number[i]) cout << i << "\n";
		int next = i + (i / 1000) + (i % 1000 / 100) + (i % 100 / 10) + i % 10;
		if (next < 10001) is_self_number[next] = 1;
	}
}