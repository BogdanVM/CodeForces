#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    int sumEven = 0, sumOdd = 0;
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i];

        if(i % 2) {
            sumEven += v[i];
        } else {
            sumOdd += v[i];
        }
    }

    int goodCandies = 0;
    int tempOdd = 0, tempEven = 0;

    for(int i = 0; i < n; ++i) {

        int resOdd = sumOdd - tempOdd + tempEven;
        int resEven = sumEven - tempEven + tempOdd;

        if(i % 2) {
            resEven -= v[i];
            tempEven += v[i];
        } else {
            resOdd -= v[i];
            tempOdd += v[i];
        }

        if(resEven == resOdd) {
            goodCandies++;
        }


    }

    std::cout << goodCandies << '\n';
    return 0;
}