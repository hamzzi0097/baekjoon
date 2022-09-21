#include <iostream>
#include <vector>
using namespace std;

int T, R;

string S;

void inputRep() {
	cin >> R >> S;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		inputRep();

		string s;
		for (int j = 0; j < S.size(); j++) {
			for (int k = 0; k < R; k++) {
				s.push_back(S[j]);
			}
		}

		cout << s << "\n";
	}
}