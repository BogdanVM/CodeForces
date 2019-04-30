#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool inBoard(int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

/**
 * Checks if a piece can be placed with the center in i and j.
 * It checks, if the neighbours are within the bounds of the board and if they're free ( == '.').
 * @param board the game board
 * @param i the row index
 * @param j the col index
 * @return true if the piece can be placed, false otherwise
 */
bool isCenter(const vector<string>& board, int i, int j) {
    int n = board.size();
    if (inBoard(i-1, j, n) && inBoard(i, j-1, n) && inBoard(i, j+1, n) && inBoard(i+1, j, n)) {
        return board[i-1][j] == '.' && board[i][j-1] == '.' && board[i][j+1] == '.' && board[i+1][j] == '.';
    }

    return false;
}

void placePiece(vector<string>& board, int i, int j) {
    board[i-1][j] = board[i][j-1] = board[i][j+1] = board[i+1][j] = board[i][j] = '#';
}

int main()
{
    int n;
    cin >> n;

    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '.') {
                if (isCenter(board, i, j)) {
                    placePiece(board, i, j);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '.') {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
    return 0;
}
