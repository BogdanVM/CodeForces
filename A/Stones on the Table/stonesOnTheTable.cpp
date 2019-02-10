#include <iostream>
#include <string>

int main()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    int nr = 0;
    for (int i = 0; i < n; i++) {

        while (s[i] == s[i+1]) {

            nr++;
            i++;
        }

    }

    std::cout << nr << "\n";
    return 0;
}