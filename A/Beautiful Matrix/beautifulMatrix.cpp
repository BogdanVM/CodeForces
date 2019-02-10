#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int oneX, oneY;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            int x;
            cin >> x;

            if (x == 1) {
                oneX = i + 1;
                oneY = j + 1;
            }

        }

    cout << abs(3 - oneX) + abs(3 - oneY) << '\n';
    return 0;
}