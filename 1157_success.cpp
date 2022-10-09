#include <iostream>
using namespace std;

string word;

int alpabet[26];
int mostAlpabet_index;
int cntMost = 0;

int main() {
	cin >> word;

	//각 알파벳이 쓰인 횟수를 배열에 저장
	for (int i = 0; i < word.size(); i++) {
		if ((int)word[i] >= 97) {
			alpabet[(int)word[i] - 97]++;
		}
		else {
			alpabet[(int)word[i] - 65]++;
		}
	}

	//가장 많이 쓰인 알파벳의 인덱스를 mostAlpabet_index에 저장
	mostAlpabet_index = 0;
	for (int i = 0; i < 26; i++) {
		if (alpabet[mostAlpabet_index] < alpabet[i]) {
			mostAlpabet_index = i;
		}
	}

	//가장 많이 쓰인 알파벳의 갯수를 cntMost에 저장
	for (int i = 0; i < 26; i++) {
		if (alpabet[mostAlpabet_index] == alpabet[i]) {
			cntMost++;
		}
	}

	if (cntMost == 1) {
		cout << (char)(mostAlpabet_index + 65);
	}
	else {
		cout << "?";
	}
}