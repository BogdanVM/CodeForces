#include <iostream>
#include <vector>
#include <string>

bool withinBoundaries(int i, int j, int n) {
    return i - 1 >= 0 && j - 1 >= 0 && i + 1 < n && j + 1 < n;
}

bool isCrossCenter(const std::vector<std::string>& matrix, int i, int j) {
    return matrix[i-1][j-1] == 'X' && matrix[i-1][j+1] == 'X' && matrix[i+1][j-1] == 'X'
        && matrix[i+1][j+1] == 'X';
}

int main() {

    int n, crosses = 0;
    std::cin >> n;

    std::vector<std::string> matrix;
    matrix.resize(n);

    for(int i = 0; i < n; ++i) {
        matrix[i].resize(n);
        for(int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(matrix[i][j] != 'X') {
                continue;
            }

            if(withinBoundaries(i, j, n)) {
                if (isCrossCenter(matrix, i, j)) {
                    crosses++;
                }
            }
        }
    }

    std::cout << crosses;
    return 0;
}