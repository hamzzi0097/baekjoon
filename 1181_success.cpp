#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool same(string word, string comp) {
	return word == comp;
}

// a�� ������ false, b�� ������ true�� ��ȯ�ϴ� �Լ�
bool comp(string a, string b) {
	if (a.length() > b.length()) return false;
	else if (a.length() < b.length()) return true;
	else {
		return a < b;
	}
}

int main() {
	int wordNum;	// �Է¹��� �ܾ��� ��
	string word;	// �ܾ �Է� �޴� string
	vector<string> output;	// ��� �迭�� �����ϴ� vector
	bool isSameWord;	// ���� �ܾ �Է� �޾Ҵ��� Ȯ�� �ϴ� bool

	cin >> wordNum;

	for (int i = 0; i < wordNum; i++) {
		isSameWord = false; // �׻� false�� �ʱ�ȭ
		cin >> word;

		output.push_back(word);
	}
	
	// sort �Լ��� ���� ���� comp �Լ��� �̿��Ͽ� ����
	sort(output.begin(), output.end(), comp);


	cout << output[0] << endl;
	for (int i = 1; i < output.size(); i++) {
		if (output[i] == output[i - 1]) {
			continue;
		}

		cout << output[i] << endl;
	}
}