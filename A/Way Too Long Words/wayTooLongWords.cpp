#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

std::string convertToString(int i)
{
    std::ostringstream buffer;
    buffer << i;
    return buffer.str();
}

int main()
{
    int n;

    std::cin >> n;

    std::vector < std::string> v;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        if (s.size() > 10) {

            std::string auxS;

            auxS = auxS + s[0]; // we add to the current string the first letter
            auxS = auxS + convertToString(s.size() - 2); // we add the number of letters
            auxS = auxS + s[s.size() - 1];

            v.push_back(auxS); // we add the modified string to the vector
        }

        else {
            /* If the number of characters is <= 10, we simply add the string to the vector */
            v.push_back(s);
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << v[i] << "\n";
    }

    return 0;
}