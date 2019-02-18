#include <iostream>
#include <string>
#include <algorithm>

bool checkAndDelete(std::string& s, char c) {
    int poz = s.find(c);
    if(poz == std::string::npos) {
        return false;
    }

    s.erase(0, poz + 1);
    return true;
}

int main()
{
    std::string s;
    std::cin >> s;

    if(!checkAndDelete(s, '[')) {
        std::cout << -1;
        return 0;
    }

    if(!checkAndDelete(s, ':')) {
        std::cout << -1;
        return 0;
    }

    /* We now reverse the string to avoid the removal of the '|' chars */
    std::reverse(s.begin(), s.end());

    if(!checkAndDelete(s, ']')) {
        std::cout << -1;
        return 0;
    }

    if(!checkAndDelete(s, ':')) {
        std::cout << -1;
        return 0;
    }

    std::cout << std::count(s.begin(), s.end(), '|') + 4;
    return 0;
}