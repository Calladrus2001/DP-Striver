#include <bits/stdc++.h> 


int frogJump(int n, vector<int> &heights)
{
    vector<int> dp (n, 0);
    for (int i = n-2; i >= 0; i--) {
        if (i == n-2) dp[i] = dp[i+1] + abs(heights[i+1] - heights[i]);
        else {
            dp[i] = min(
                dp[i+1] + abs(heights[i+1] - heights[i]),
                dp[i+2] + abs(heights[i+2] - heights[i])
            );
        }
    }
    return dp[0];
}