#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> split(const std::string& s) {

    std::vector<int> v;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != '+')
            v.push_back(s[i] - '0');

    return v;
}

int main()
{
    std::string s;
    std::cin >> s;

    std::vector<int> v = split(s);
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
        if (i == v.size() - 1)
           std::cout << v[i] << "\n";
        else
           std::cout << v[i] << "+";

    return 0;
}