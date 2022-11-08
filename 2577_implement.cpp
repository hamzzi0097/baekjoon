#include <iostream>
#include <string>
using namespace std;

int a, b, c;
string result;

int main() {
	cin >> a >> b >> c;
	result = to_string(a * b * c);
	
	for (int i = 0; i < 10; i++) {
		int cnt = 0;
		
		for (int j = 0; j < result.size(); j++) {
			if (result[j] == i + 48) {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
}