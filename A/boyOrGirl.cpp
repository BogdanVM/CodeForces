#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>

int main()
{
    std::string userName;
    std::cin >> userName;

    std::set<char> distinctChars;
    int n = userName.size();

    for (int i = 0; i < n; ++i) {
        distinctChars.insert(userName[i]);
    }

    if (distinctChars.size() % 2) {
        std::cout << "IGNORE HIM!";
    } else {
        std::cout << "CHAT WITH HER!";
    }
    return 0;
}