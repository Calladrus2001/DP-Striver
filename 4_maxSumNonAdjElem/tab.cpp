#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp (n, 0);
    dp[n-1] = nums[n-1];
    
    for (int i = n-2; i >= 0; i--) {
        int pick = nums[i] + ((i < n-2) ? dp[i+2] : 0);
        int notPick = dp[i+1];
        dp[i] = max(pick, notPick);
    }
    return dp[0];
}