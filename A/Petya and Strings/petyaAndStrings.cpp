#include <iostream>
#include <string>

std::string lowerCase(const std::string& s) {
    std::string auxS(s);

    for (int i = 0; i < auxS.size(); i++)
        if (auxS[i] >= 'A' && auxS[i] <= 'Z')
            auxS[i] = auxS[i] + 32;

    return auxS;
}

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    s1 = lowerCase(s1);
    s2 = lowerCase(s2);

    if (s1 < s2) {
        std::cout << "-1\n";
    }

    else if (s1 > s2) {
        std::cout << "1\n";
    }

    else {
        std::cout << "0\n";
    }
    return 0;
}