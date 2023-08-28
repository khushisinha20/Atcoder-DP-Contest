#include <bits/stdc++.h>
using namespace std;

/*  MEMOIZATION
int helper(vector<int>& heights, vector<int>& dp, int index, int& k) {
    if (index == heights.size() - 1)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int result = INT_MAX;
    for (int i = 1; i <= k and index + i < heights.size(); ++i) {
        int cost = abs(heights[index] - heights[index + i]) + helper(heights, dp, index + i, k);
        result = min(result, cost);
    }

    return dp[index] = result;
}

int minPossibleCost(vector<int>& heights, int& k) {
    int n = heights.size();
    vector<int> dp(n, -1);
    return helper(heights, dp, 0, k);
}*/

/*ITERATION*/


int minPossibleCost(vector<int>& heights, int& k) {
    int n = heights.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0; 

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= i + k && j < n; ++j) {
            int cost = abs(heights[i] - heights[j]) + dp[i];
            dp[j] = min(dp[j], cost);
        }
    }

    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i)
        cin >> heights[i];

    cout << minPossibleCost(heights, k) << '\n';

    return 0;
}