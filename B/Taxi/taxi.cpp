#include <algorithm>
#include <vector>
#include <iostream>

void read(std::vector<int>& v) {
    int n;
    std::cin >> n;

    v.resize(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}

int splitInGroups(std::vector<int>& v) {
    int rides = 0;
    int i = 0, j = v.size() - 1;
    int currentSize = 0;

    while(i < j){
        if (v[i] + v[j] <= 4) {
            v[j] += v[i];
            i++;
        } else {
            j--;
            currentSize++;
        }
    }

    return currentSize + 1;
}

int main()
{
    std::vector<int> v;
    read(v);

    std::sort(v.begin(), v.end());

    std::cout << splitInGroups(v);
    std::cout << '\n';
    return 0;
}