#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    
    for (int i = 0; i < s.size(); i++) {
       
        int nr = 1;
        while (s[i] == s[i+1])
        {
            nr++;
            i++;
        }
        
        if (nr >= 7)
        {
            std::cout << "YES\n";
            return 0;
        }
    }
    
    std::cout << "NO\n";
    return 0;
}