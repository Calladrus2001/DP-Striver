#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
  int helper(vector<int> wt, vector<int> val, int idx, int W, vector<vector<int>> &dp);
  return helper(weight, value, n - 1, maxWeight, dp);
}

int helper(vector<int> wt, vector<int> val, int idx, int W, vector<vector<int>> &dp)
{
  if (idx == 0)
  {
    if (wt[idx] <= W)
      return val[idx];
    else
      return 0;
  }
  if (dp[idx][W] != -1)
    return dp[idx][W];

  int pick = -1e8;
  if (wt[idx] <= W)
    pick = val[idx] + helper(wt, val, idx - 1, W - wt[idx], dp);
  int notPick = 0 + helper(wt, val, idx - 1, W, dp);

  return dp[idx][W] = max(pick, notPick);
}