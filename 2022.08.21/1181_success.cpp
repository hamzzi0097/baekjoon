#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool same(string word, string comp) {
	return word == comp;
}

// a가 먼저면 false, b가 먼저면 true를 반환하는 함수
bool comp(string a, string b) {
	if (a.length() > b.length()) return false;
	else if (a.length() < b.length()) return true;
	else {
		return a < b;
	}
}

int main() {
	int wordNum;	// 입력받을 단어의 수
	string word;	// 단어를 입력 받는 string
	vector<string> output;	// 출력 배열을 저장하는 vector
	bool isSameWord;	// 같은 단어를 입력 받았는지 확인 하는 bool

	cin >> wordNum;

	for (int i = 0; i < wordNum; i++) {
		isSameWord = false; // 항상 false로 초기화
		cin >> word;

		output.push_back(word);
	}
	
	// sort 함수와 직접 만든 comp 함수를 이용하여 정렬
	sort(output.begin(), output.end(), comp);


	cout << output[0] << endl;
	for (int i = 1; i < output.size(); i++) {
		if (output[i] == output[i - 1]) {
			continue;
		}

		cout << output[i] << endl;
	}
}
