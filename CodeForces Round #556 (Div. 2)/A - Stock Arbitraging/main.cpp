#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> s(n);
    vector<int> b(m);

    int minimum = 1001;
    int maximum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i] < minimum) {
            minimum = s[i];
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        if (b[i] > maximum) {
            maximum = b[i];
        }
    }

    if (minimum > maximum) {
        cout << r;
        return 0;
    }

    int shares = 0;
    shares += r / minimum;
    r -= minimum * shares;

    r += maximum * shares;
    cout << r;

    return 0;
}
