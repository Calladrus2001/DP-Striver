#include <bits/stdc++.h> 

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp (n, 1e9);
    dp[n-1] = 0;

    for (int i = n-2; i >= 0; i--) {
        for (int j = 1; j <= k; j++) {
            if (i+j <= n-1) {
                dp[i] = min(dp[i], dp[i+j] + abs(height[i+j] - height[i]));
            }
            else break;
        }
    }
    return dp[0];
}