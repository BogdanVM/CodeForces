#include <iostream>

int main()
{
    long long n, m, a;
    std::cin >> n >> m >> a;

    /* We calculate the number of stones needed to cover the rows, respectively the columns:
    -  if the no. rows ( no. cols ) is divisible with the flagstone size, then we simply divide them;
    -  else, we divide them and add one */
    long long coverRows = m % a ? (m / a) + 1 : (m / a);
    long long coverCols = n % a ? (n / a) + 1 : (n / a);

    std::cout << coverRows * coverCols << "\n";
    return 0;
}