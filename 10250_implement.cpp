#include <iostream>
using namespace std;

int T, H, W, N, h, w;

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> H >> W >> N;
        
        if (N % H == 0) {
            h = H;
            w = N / H;
        }
        else {
            h = N % H;
            w = N / H + 1;
        }

        if (w < 10) {
            cout << h << 0 << w << "\n";
        }
        else {
            cout << h << w << "\n";
        }
    }
}