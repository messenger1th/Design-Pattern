#include <bits/stdc++.h>

using namespace std;

int maxCoinsByRecursion(const vector<int>& coins, int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return coins[0];
    }
    return max(maxCoinsByRecursion(coins, n - 2) + coins[n - 1], maxCoinsByRecursion(coins, n - 1));
}

int maxCoinsByIteration(const vector<int>& coins, int n) {
    if (n == 0) {
        return 0;
    }
    int prev = 0, curr = coins[0];
    for (int i = 1; i < n; ++i) {
        int temp = max(prev + coins[i], curr);
        prev = curr;
        curr = temp;
    }
    return curr;
}

int main() {
    cout << maxCoinsByIteration({5, 1, 2, 10, 6, 2}, 1);
}
