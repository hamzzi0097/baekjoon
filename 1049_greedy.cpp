#include <iostream>
using namespace std;

int N, M;
int six_min_price = 1001, one_min_price = 1001;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		if (a < six_min_price) six_min_price = a;
		if (b < one_min_price) one_min_price = b;
	}
	
	// 6개짜리로 구매한 후, 1개짜리로 부족한 줄을 구매한 경우
	int min_price = N / 6 * six_min_price + N % 6 * one_min_price;
	
	// 6개짜리로 전부 구매한 경우
	if (min_price > (N / 6 + 1) * six_min_price)
		min_price = (N / 6 + 1) * six_min_price;

	// 1개짜리로 전부 구매한 경우
	if (N * one_min_price < min_price)
		min_price = N * one_min_price;

	cout << min_price;
}