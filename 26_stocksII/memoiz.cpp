#include <bits/stdc++.h> 
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (3, -1)));
    int helper(vector<int> &arr, int idx, int canBuy, int cap, vector<vector<vector<int>>> &dp);
    return helper(prices, 0, 1, 2, dp);
}

int helper(vector<int> &arr, int idx, int canBuy, int cap, vector<vector<vector<int>>> &dp){
    if (cap == 0 || idx == arr.size()) return 0;
    if (dp[idx][canBuy][cap] != -1) return dp[idx][canBuy][cap];
    
    if (canBuy) {
        return max(helper(arr, idx+1, 0, cap, dp) - arr[idx], helper(arr, idx+1, 1, cap, dp));
    }
    return dp[idx][canBuy][cap] = max(arr[idx] + helper(arr, idx + 1, 1, cap-1, dp), helper(arr, idx + 1, 0, cap, dp));
}
