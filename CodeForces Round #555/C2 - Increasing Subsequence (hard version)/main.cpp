#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Finds the number that breaks the strictly increasing sequence starting from the specified position.
 * @param v vector of ints
 * @param start start index from where to search
 * @param right if true => the search will be done from the right side of the array
 * @return index of the element that breaks the strictly increasing sequence
 */
int findPivotPosition(const vector<int>& v, int start, bool right = false) {
    while (true) {
        if (right) {
            if (v[start] >= v[start-1]) {
                return start-1;
            }
            start--;
        } else {
            if (v[start] >= v[start+1]) {
                return start+1;
            }
            start++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if (n == 1) {
        cout << 1 << '\n' << 'L';
        return 0;
    }

    int currentNumber = 0;
    int left = 0;
    int right = n-1;
    string sequence;

    while (left <= right) {
        if (currentNumber < v[left] && currentNumber < v[right]) {
            if (v[left] < v[right]) {
                sequence.push_back('L');
                currentNumber = v[left++];
            } else if (v[right] < v[left]){
                sequence.push_back('R');
                currentNumber = v[right--];
            } else if (v[right] == v[left]){
                int posRight = findPivotPosition(v, right, true);
                int posLeft = findPivotPosition(v, left);

                /* Numbers added to the sequence if we choose the right or the left side */
                int addedRight = right - posRight;
                int addedLeft = posLeft - left;

                if (addedLeft > addedRight) {
                    sequence.push_back('L');
                    currentNumber = v[left++];
                } else {
                    sequence.push_back('R');
                    currentNumber = v[right--];
                }
            }
        } else {
            if (currentNumber < v[left]) {
                sequence.push_back('L');
                currentNumber = v[left++];
            } else if (currentNumber < v[right]) {
                sequence.push_back('R');
                currentNumber = v[right--];
            } else {
                break;
            }
        }
    }

    cout << sequence.size() << '\n' << sequence;
    return 0;
}
