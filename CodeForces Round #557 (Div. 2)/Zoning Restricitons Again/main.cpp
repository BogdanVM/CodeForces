#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h, m;
    cin >> n >> h >> m;

    vector<int> maxHeight(n+1, h);
    for (int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;

        maxHeight[l] = min(maxHeight[l], x);
        maxHeight[r] = min(maxHeight[r], x);
    }

    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += maxHeight[i] * maxHeight[i];
    }

    cout << sum;
    return 0;
}