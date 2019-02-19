#include <iostream>
#include <algorithm>

int main()
{
    int q, a, b;
    std::cin >> q;

    long long n;
    for(int i = 0; i < q; ++i) {
        std::cin >> n >> a >> b;
        if(n == 1) {
            std::cout << a << "\n";
            continue;
        }

        long long res = std::min(a * n, b * (n / 2) + a * (n % 2));
        std::cout << res << "\n";
    }
    return 0;
}