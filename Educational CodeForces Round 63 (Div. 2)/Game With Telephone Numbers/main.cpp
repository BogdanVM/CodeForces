#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    bool vasya = true;

    while (s.size() != 11) {
        if (vasya) {
            if (s[0] != '8') {
                s.erase(s.begin());
            } else {
                size_t first_not_8_digit = s.find_first_not_of('8');

                if (first_not_8_digit != string::npos) {
                    s.erase(s.begin() + first_not_8_digit);
                } else {
                    break;
                }
            }

            vasya = false;
        } else {
            if (s[0] == '8') {
                s.erase(s.begin());
            } else {
                size_t first_8_digit = s.find_first_of('8');

                if (first_8_digit != string::npos) {
                    s.erase(s.begin() + first_8_digit);
                } else {
                    break;
                }
            }

            vasya = true;
        }
    }

    if (s[0] == '8') {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
