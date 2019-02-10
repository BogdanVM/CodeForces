#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;
    
    int x = 0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        
        if (s == "X++" || s == "++X")
           x++;
        else if (s == "X--" || s == "--X")
           x--;
    }
    
    std::cout << x << "\n";
    return 0;
}