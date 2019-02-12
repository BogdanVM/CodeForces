#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    int a, b;
    std::cin >> a >> b;

    int maxCapacity = b;
    int currentCapacity = b;

    for (int i = 1; i < n; ++i) {
        std::cin >> a >> b;
        currentCapacity -= a - b;

        if (currentCapacity > maxCapacity) {
            maxCapacity = currentCapacity;
        }
    }

    std::cout << maxCapacity;
    return 0;
}