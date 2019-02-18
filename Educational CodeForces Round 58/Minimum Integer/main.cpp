#include <iostream>

int main()
{
    int n, l, r, d;
    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        std::cin >> l >> r >> d;

        if(d < l) {
            std::cout << d << '\n';
        } else {
            std::cout << ((r / d) + 1) * d << '\n';
        }
    }
    return 0;
}