#include <iostream>
using namespace std;

string word;

int alpabet[26];
int mostAlpabet_index;
int cntMost = 0;

int main() {
	cin >> word;

	//�� ���ĺ��� ���� Ƚ���� �迭�� ����
	for (int i = 0; i < word.size(); i++) {
		if ((int)word[i] >= 97) {
			alpabet[(int)word[i] - 97]++;
		}
		else {
			alpabet[(int)word[i] - 65]++;
		}
	}

	//���� ���� ���� ���ĺ��� �ε����� mostAlpabet_index�� ����
	mostAlpabet_index = 0;
	for (int i = 0; i < 26; i++) {
		if (alpabet[mostAlpabet_index] < alpabet[i]) {
			mostAlpabet_index = i;
		}
	}

	//���� ���� ���� ���ĺ��� ������ cntMost�� ����
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