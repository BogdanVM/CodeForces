#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int left = 0, right = n - 1;
    long long sum = 0;

    while(left <= right) {
        sum += (a[left]+ a[right]) * (a[left] + a[right]);
        left++;
        right--;
    }

    std::cout << sum;
    return 0;
}