//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool same(string word, string comp) {
//	return word == comp;
//}
//
//// a�� ������ false, b�� ������ true�� ��ȯ�ϴ� �Լ�
//bool comp(string a, string b) {
//	if (a.length() > b.length()) return false;
//	else if (a.length() < b.length()) return true;
//	else {
//		return a < b;
//	}
//}
//
//int main() {
//	int wordNum;	// �Է¹��� �ܾ��� ��
//	string word;	// �ܾ �Է� �޴� string
//	vector<string> output;	// ��� �迭�� �����ϴ� vector
//	bool isSameWord;	// ���� �ܾ �Է� �޾Ҵ��� Ȯ�� �ϴ� bool
//
//	cin >> wordNum;
//
//	for (int i = 0; i < wordNum; i++) {
//		isSameWord = false; // �׻� false�� �ʱ�ȭ
//		cin >> word;
//
//		// ���� �ܾ �ִٸ� ���� �ܾ �������� ����
//		for (int j = 0; j < output.size(); j++) {
//			if (word == output[j]) {
//				isSameWord = true;
//				break;
//			}
//		}
//		if (isSameWord) continue;
//
//		output.push_back(word);
//	}
//
//	// sort �Լ��� ���� ���� comp �Լ��� �̿��Ͽ� ����
//	sort(output.begin(), output.end(), comp);
//
//	for (int i = 0; i < output.size(); i++) {
//		cout << output[i] << endl;
//	}
//}