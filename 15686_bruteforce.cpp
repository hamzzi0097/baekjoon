#include <iostream>
#include <vector>
using namespace std;

int N, M;
int map[50][50];

int house_cnt = 0;
int restaurant_cnt = 0;
pair<int, int> house_pos[100];
pair<int, int> restaurant_pos[13];


// ���� ġŲ�� 
vector<int> left_restaurant;

// ����� ġŲ��
vector<int> closed_restaurant;

// �ּ� ġŲ�Ÿ�
int min_distance = -1;

// �� �� ������ �Ÿ� ���ϴ� �Լ�
int get_distance(pair<int, int> p1, pair<int, int> p2) {
	int x_val = p1.first - p2.first;
	if (x_val < 0) x_val *= -1;

	int y_val = p1.second - p2.second;
	if (y_val < 0) y_val *= -1;

	return x_val + y_val;
}

// ������ ġŲ�Ÿ� ���ϴ� �Լ�
int get_chicken_distance() {
	int total_distance = 0;
	for (int house_index = 0; house_index < house_cnt; house_index++) {
		int min_dis = 2*N + 1;
		for (auto iter = left_restaurant.begin(); iter != left_restaurant.end(); iter++) {
			int dis = get_distance(house_pos[house_index], restaurant_pos[*iter]);
			if (dis < min_dis)
				min_dis = dis;
		}
		total_distance += min_dis;
	}
	return total_distance;
}

// �ּ� ġŲ�Ÿ� ���ϴ� �Լ�
void get_min_chicken_distance(int restaurant_index) {
	// M���� ġŲ�� ���� �Ϸ� ��, ġŲ�Ÿ� ��
	if (left_restaurant.size() == M) {
		int val = get_chicken_distance();
		if (min_distance < 0)
			min_distance = val;
		else if (min_distance > val)
			min_distance = val;
		return;
	}

	// �ش� ġŲ���� ������ ���
	if (left_restaurant.size() < M) {
		left_restaurant.push_back(restaurant_index);
		get_min_chicken_distance(restaurant_index + 1);
		left_restaurant.pop_back();
	}

	// ���ܾ��� ġŲ�� �� > ���� ġŲ�� �� ��� 
	// �ش� ġŲ���� ��������� ���
	if (closed_restaurant.size() < restaurant_cnt - M) {
		closed_restaurant.push_back(restaurant_index);
		get_min_chicken_distance(restaurant_index + 1);
		closed_restaurant.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				house_pos[house_cnt] = { i,j };
				house_cnt++;
			}

			if (map[i][j] == 2) {
				restaurant_pos[restaurant_cnt] = { i,j };
				restaurant_cnt++;
			}
		}
	}
	get_min_chicken_distance(0);

	cout << min_distance;
}