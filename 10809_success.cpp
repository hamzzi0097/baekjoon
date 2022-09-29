#include <iostream>
using namespace std;

int isAlphabet[26];
string s;

int main() {
	for (int i = 0; i < 26; i++) {
		isAlphabet[i] = -1;
	}

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		int index = (int)s[i] - 97;
		if (isAlphabet[index] == -1) isAlphabet[index] = i;
	}
	
	for (int i = 0; i < 26; i++) {
		cout << isAlphabet[i] << " ";
	}
}