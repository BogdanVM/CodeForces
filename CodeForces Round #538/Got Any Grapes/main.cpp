#include <iostream>
#include <vector>
#include <algorithm>

bool enoughGrapes(const std::vector<int>& input) {
    int x = input[0], y = input[1], z = input[2];
    int a = input[3], b = input[4], c = input[5];
    if(x > a) {
        return false;
    }

    a -= x;
    if(y > a + b) {
        return false;
    }

    int temp = a;
    a = std::max(a - y, 0);
    y = std::max(y - temp, 0);

    if(y != 0) {
        b -= y;
    }

    return z <= a + b + c;
}

int main()
{
    int x, y, z;
    int a, b, c;

    std::cin >> x >> y >> z;
    std::cin >> a >> b >> c;

    if(enoughGrapes(std::vector<int>({x, y, z, a, b, c}))) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}