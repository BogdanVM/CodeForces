#include <iostream>
#include <vector>
#include <algorithm>

struct Burger {
    int noPatties;
    int pricePerPatty;
};

bool compareByPrice(const Burger& a, const Burger& b) {
    return a.pricePerPatty > b.pricePerPatty;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int b;
        std::cin >> b;

        std::vector<Burger> burgers(2);
        std::cin >> burgers[0].noPatties >> burgers[1].noPatties; 
        std::cin >> burgers[0].pricePerPatty >> burgers[1].pricePerPatty;

        std::sort(burgers.begin(), burgers.end(), compareByPrice);
        
        int sum = 0;
        for (int j = 0; j < 2; ++j) {
            if (b >= burgers[j].noPatties * 2) {
                b -= burgers[j].noPatties * 2;
                sum += burgers[j].pricePerPatty * burgers[j].noPatties;
            } else {
                std::cout << sum + burgers[j].pricePerPatty * (b / 2) << std::endl;
                b = -1;
                break;
            }      
        }

        if (b != -1) {
            std::cout << sum << std::endl;
        }
    } 

    return 0;
}
