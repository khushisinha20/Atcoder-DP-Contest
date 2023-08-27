#include <bits/stdc++.h>
using namespace std;

/*
MEMOIZATION
int helper(vector<int>& heights, int index, vector<int>& dp) {
    if (index >= heights.size() - 1)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int jumpToNext = INT_MAX;
    if (index + 1 < heights.size())
        jumpToNext = abs(heights[index + 1] - heights[index]) + helper(heights, index + 1, dp);

    int jumpToSecondNext = INT_MAX;
    if (index + 2 < heights.size())
        jumpToSecondNext = abs(heights[index + 2] - heights[index]) + helper(heights, index + 2, dp);

    return dp[index] = min(jumpToNext, jumpToSecondNext);
}

int minPossibleCost(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, -1);
    return helper(heights, 0, dp);
}*/

/*ITERATIVE*/

int minPossibleCost(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        int jumpToPrevious = INT_MAX;
        if (i - 1 >= 0) 
            jumpToPrevious = abs(heights[i] - heights[i - 1]) + dp[i - 1]; 
        int jumpToSecondPrevious = INT_MAX;
        if (i - 2 >= 0) 
            jumpToSecondPrevious = abs(heights[i] - heights[i - 2]) + dp[i - 2]; 
        dp[i] = min(jumpToPrevious, jumpToSecondPrevious);
    }

    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i)
        cin >> heights[i];

    cout << minPossibleCost(heights) << '\n';

    return 0;
}