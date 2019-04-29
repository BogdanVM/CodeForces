#include <iostream>
#include <vector>
#include <map>

using namespace std;

class LongNumber {
    vector<int> digits;
    map<int, int> f;

    public:
        void addDigit(char c) {
            digits.push_back(c - '0');
        }

        void addF(int key, int value) {
            f[key] = value;
        }

        void maximum() {
            bool started = false, ended = false;
            for (int digit : digits) {
                if (started) {
                    /* If the sequence to be replaced has started */
                    if (ended) {
                        /* If the sequence has ended, just display the digit */
                        cout << digit;
                    } else {
                        /* If the sequence is still going, check the digit */
                        if (digit <= f[digit]) {
                            /* If it's still optimal to replace the current digit, replace it */
                            cout << f[digit];
                        } else {
                            /* If not replacing the current digit would be optimal, then end the sequence*/
                            cout << digit;
                            ended = true;
                        }
                    }
                } else {
                    /* If the sequence to be replaced has not started */
                    if (digit < f[digit]) {
                        /* If the current digit does not provide an optimal solutin, then replace it
                         * and start the sequence */
                        cout << f[digit];
                        started = true;
                    } else {
                        /* If the current digit is optimal, display it */
                        cout << digit;
                    }
                }
            }
        }
};

int main()
{
    int n;
    cin >> n;

    LongNumber number;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;

        number.addDigit(c);
    }

    for (int i = 0; i < 9; ++i) {
        int f;
        cin >> f;

        number.addF(i + 1, f);
    }

    number.maximum();
    return 0;
}
