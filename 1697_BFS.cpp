#include <iostream>
#include <queue>
using namespace std;

int N, K;
int depth[100001] = { 0, };

bool visited[100001] = { 0, };

queue<int> q;

void BFS(int root) {
	q.push(root);
	visited[root] = true;
	depth[root] = 0;

	while (!q.empty()) {
		// queue의 첫번째 값을 dequeue
		int node = q.front();
		q.pop();
		
		if (node == K) {
			cout << depth[node];
			return;
		}

		if (node-1 >= 0 && !visited[node - 1]) {
			visited[node - 1] = true;
			q.push(node - 1);
			depth[node - 1] = depth[node] + 1;
		}

		if (node + 1 <= 100000 && !visited[node + 1]) {
			visited[node + 1] = true;
			q.push(node + 1);
			depth[node + 1] = depth[node] + 1;
		}

		if (node * 2 <= 100000 && !visited[node * 2]) {
			visited[node * 2] = true;
			q.push(node * 2);
			depth[node * 2] = depth[node] + 1;
		}
	}
	return;
}

int main() {
	cin >> N >> K;

	BFS(N);
}