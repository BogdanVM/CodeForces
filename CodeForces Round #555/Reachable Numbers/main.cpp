#include <iostream>
#include <set>

using namespace std;

void removeZeroes(long long& n) {
    while (n % 10 == 0) {
        n /= 10;
    }
}

void f(long long& n) {
    if (n % 10 != 0) {
        n++;
    }

    removeZeroes(n);
}

int main()
{
    long long n;
    cin >> n;

    set<long long> reachableNumbers;
    reachableNumbers.insert(n);

    if (n % 10 == 0) {
        reachableNumbers.insert(++n);
    }

    while (true) {
        f(n);

        bool inserted = reachableNumbers.insert(n).second;
        if (!inserted) {
            break;
        }
    }

    cout << reachableNumbers.size();
    return 0;
}
