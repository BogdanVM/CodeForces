#include <iostream>

int main() 
{
    int n;
    std::cin >> n;
    
    int nr = 0;
    for (int i = 0; i < n; i++) {
       
        int x, y, z;
        std::cin >> x >> y >> z;
        
        if (x + y + z >= 2)
           nr++;
    }
    
    std::cout << nr << "\n";
    return 0;
}