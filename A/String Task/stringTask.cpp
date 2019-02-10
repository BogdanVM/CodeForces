#include <string>
#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;

    std::string vowels("aeiouyAEIOUY");
    std::string finalWord("");

    for (int i = 0; i < s.size(); i++) {
        /* If the current letter is a vowel, we ignore it */
        if (vowels.find(s[i]) != std::string::npos)
            continue;

        finalWord += ".";
        if (s[i] >= 'B' && s[i] <= 'Z')
            finalWord += s[i] + 32;
        else
            finalWord += s[i];
    }

    std::cout << finalWord << "\n";
    return 0;
}