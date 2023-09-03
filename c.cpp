#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

/*  MEMOIZATION
int helper(vector<int>& a, vector<int>& b, vector<int>& c, int day, int previousActivity) {
    if (day == a.size())
        return 0;

    if (dp[day][previousActivity] != -1)
        return dp[day][previousActivity];

    int maxHappiness = 0;

    if (previousActivity == 0) {
        maxHappiness = max(maxHappiness, a[day] + helper(a, b, c, day + 1, 1));
        maxHappiness = max(maxHappiness, b[day] + helper(a, b, c, day + 1, 2));
        maxHappiness = max(maxHappiness, c[day] + helper(a, b, c, day + 1, 3));
    } else if (previousActivity == 1) {
        maxHappiness = max(maxHappiness, b[day] + helper(a, b, c, day + 1, 2));
        maxHappiness = max(maxHappiness, c[day] + helper(a, b, c, day + 1, 3));
    } else if (previousActivity == 2) {
        maxHappiness = max(maxHappiness, a[day] + helper(a, b, c, day + 1, 1));
        maxHappiness = max(maxHappiness, c[day] + helper(a, b, c, day + 1, 3));
    } else {
        maxHappiness = max(maxHappiness, a[day] + helper(a, b, c, day + 1, 1));
        maxHappiness = max(maxHappiness, b[day] + helper(a, b, c, day + 1, 2));
    }

    return dp[day][previousActivity] = maxHappiness;
}

int maxPoints(vector<int>& a, vector<int>& b, vector<int>& c) {
    int n = a.size();
    dp.resize(n, vector<int> (4, -1));
    return helper(a, b, c, 0, 0);
}*/

int maxPoints(vector<int>& a, vector<int>& b, vector<int>& c) {
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int> (4, 0));

    for (int day = n - 1; day >= 0; --day) {
        for (int previousActivity = 0; previousActivity < 4; ++previousActivity) {
            int maxHappiness = 0;

            if (previousActivity == 0) {
                maxHappiness = max(maxHappiness, a[day] + dp[day + 1][1]);
                maxHappiness = max(maxHappiness, b[day] + dp[day + 1][2]);
                maxHappiness = max(maxHappiness, c[day] + dp[day + 1][3]);
            } else if (previousActivity == 1) {
                maxHappiness = max(maxHappiness, b[day] + dp[day + 1][2]);
                maxHappiness = max(maxHappiness, c[day] + dp[day + 1][3]);
            } else if (previousActivity == 2) {
                maxHappiness = max(maxHappiness, a[day] + dp[day + 1][1]);
                maxHappiness = max(maxHappiness, c[day] + dp[day + 1][3]);
            } else {
                maxHappiness = max(maxHappiness, a[day] + dp[day + 1][1]);
                maxHappiness = max(maxHappiness, b[day] + dp[day + 1][2]);
            }

            dp[day][previousActivity] = maxHappiness;
        }
    }

    return dp[0][0];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];

    cout << maxPoints(a, b, c) << '\n';
}