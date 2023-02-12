#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;

unordered_map<int, string> pocketmon_name;
unordered_map<string, int> pocketmon_num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string name;
		cin >> name;
		pocketmon_name.insert(unordered_map<int, string>::value_type(i, name));
		pocketmon_num.insert(unordered_map<string, int>::value_type(name, i));
	}

	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;

		if (input[0] >= 'A' && input[0] <= 'Z') {
			cout << pocketmon_num.find(input)->second << "\n";
		}
		else {
			cout << pocketmon_name.find(stoi(input))->second << "\n";
		}
	}
}

