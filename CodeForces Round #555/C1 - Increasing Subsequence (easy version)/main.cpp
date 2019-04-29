#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, char>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = 'N';
    }

    if (n == 1) {
        cout << 1 << '\n' << 'L';
        return 0;
    }

    int currentNumber = 0;
    int left = 0;
    int right = n-1;
    string sequence;

    v[0].second = 'L';
    v[n-1].second = 'R';
    while (left <= right) {
        if (currentNumber < v[left].first && currentNumber < v[right].first) {
            if (v[left].first < v[right].first) {
                sequence.push_back(v[left].second);
                currentNumber = v[left].first;
                left++;

                if (v[left].second == 'N') {
                    v[left].second = 'L';
                }
            } else {
                sequence.push_back(v[right].second);
                currentNumber = v[right].first;
                right--;

                if (right >= 0) {
                    if (v[right].second == 'N') {
                        v[right].second = 'R';
                    }
                }
            }
        } else {
            if (currentNumber < v[left].first) {
                sequence.push_back(v[left].second);
                currentNumber = v[left].first;
                left++;
            } else if (currentNumber < v[right].first) {
                sequence.push_back(v[right].second);
                currentNumber = v[right].first;
                right--;
            } else {
                break;
            }

            if (v[left].second == 'N') {
                v[left].second = 'L';
            }

            if (right >= 0) {
                if (v[right].second == 'N') {
                    v[right].second = 'R';
                }
            }
        }
    }

    cout << sequence.size() << '\n' << sequence;
    return 0;
}
