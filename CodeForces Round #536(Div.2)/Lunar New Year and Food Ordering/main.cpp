#include <iostream>
#include <vector>
#include <algorithm>

class Dish {
    long long cost;
    long long quantity;
    long long index;

public:
    Dish(long long _quantity = 0, long long _index = 0, long long _cost = 0) : cost(_cost), index(_index), quantity(_quantity) {}

    long long getCost() const { return cost; }
    long long getQuantity() const { return quantity; }
    long long getIndex() const { return index; }
    void setCost(long long _cost) { cost = _cost; }
    void setQuantity(long long _quantity) { quantity = _quantity; }

    bool operator < (const Dish& dish) {
        return (cost < dish.cost) || (cost == dish.cost && index < dish.index);
    }
};

int main() {
    long long n, m, x, y;
    std::cin >> n >> m;

    std::vector<Dish> dishes;
    for(long long i = 0; i < n; ++i) {
        std::cin >> x;
        dishes.emplace_back(x, i);
    }

    for(long long i = 0; i < n; ++i) {
        std::cin >> x;
        dishes[i].setCost(x);
    }

    std::vector<long long> indices(n);
    std::sort(dishes.begin(), dishes.end());

    for(long long i = 0; i < n; ++i) {
        indices[dishes[i].getIndex()] = i;
    }

    long long j = 0;
    for(long long i = 0; i < m; ++i) {
        std::cin >> x >> y;

        long long poz = indices[x-1];
        long long quant = dishes[poz].getQuantity();
        long long cost = dishes[poz].getCost();
        long long sum = 0;


        if(quant >= y) {
            dishes[poz].setQuantity(quant - y);
            sum += cost * y;
        }

        else {
            dishes[poz].setQuantity(0);

            sum += cost * quant;
            y -= quant;

            while(j < n && y > 0) {
                quant = dishes[j].getQuantity();
                cost = dishes[j].getCost();

                if(quant >= y) {
                    dishes[j].setQuantity(quant - y);
                    sum += cost * y;
                    y -= quant;
                }
                else {
                    dishes[j++].setQuantity(0);
                    sum += cost * quant;
                    y -= quant;
                }
            }

            if(y > 0) {
                sum = 0;
            }
        }

        std::cout << sum << "\n";
    }
    return 0;
}