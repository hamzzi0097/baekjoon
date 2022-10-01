#include <iostream>
#include <vector>
using namespace std;

int computerNum, edgeNum;
int infectedCom = 0;

vector<pair<int, int>> edges;
vector<int> infectedList;

void moveVirus(vector<pair<int, int>> v, int currentComputer) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == currentComputer) {
			bool isInfected = false;
			for (int j = 0; j < infectedList.size(); j++) {
				if (infectedList[j] == v[i].second) {
					isInfected = true;
					break;
				}
			}
			if (!isInfected) {
				infectedCom++;
				infectedList.push_back(v[i].second);
				moveVirus(v, v[i].second);
			}
		}
		if (v[i].second == currentComputer) {
			bool isInfected = false;
			for (int j = 0; j < infectedList.size(); j++) {
				if (infectedList[j] == v[i].first) {
					isInfected = true;
					break;
				}
			}
			if (!isInfected) {
				infectedCom++;
				infectedList.push_back(v[i].first);
				moveVirus(v, v[i].first);
			}
		}
	}
}

int main() {
	cin >> computerNum >> edgeNum;

	for (int i = 0; i < edgeNum; i++) {
		int a, b;
		cin >> a >> b;
		edges.push_back({ a,b });
	}

	infectedList.push_back(1);
	moveVirus(edges, 1);

	cout << infectedCom;
}