#include <iostream>

int main()
{
    int k, n;
    int kth; // hold the score of the kth participant
    int noAccepted = 0;

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {

        int x;
        std::cin >> x;

        if (x == 0)
            continue;

        if (i == k)
            kth = x;
        else if (i > k && x < kth)
            continue;

        noAccepted++;
    }

    std::cout << noAccepted << "\n";
    return 0;
}