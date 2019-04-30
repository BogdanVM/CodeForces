#include <iostream>
#include <vector>

using namespace std;

bool sorted(const vector<int>& v, int left, int right) {
    for (int i = left; i < right; ++i) {
        if (v[i] > v[i+1]) {
            return false;
        }
    }

    return true;
}

int longestSortedSubsequence(const vector<int>& v, int left, int right) {
    if (left == right) {
        return 1;
    }

    if (sorted(v, left, right)) {
        return right - left + 1;
    }

    int middle = (left + right) / 2;

    int leftSide = longestSortedSubsequence(v, left, middle);
    int rightSide = longestSortedSubsequence(v, middle+1, right);

    return max(leftSide, rightSide);
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << longestSortedSubsequence(v, 0, n-1);
    return 0;
}