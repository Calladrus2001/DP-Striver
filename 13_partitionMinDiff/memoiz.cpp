#include <bits/stdc++.h>
int minSubsetSumDifference(vector<int> &arr, int n)
{
  int helper(vector<int> & arr, int total, int sum1, int idx, vector<vector<int>> &dp);
  int total = 0;
  for (int i = 0; i < n; i++)
    total += arr[i];

  vector<vector<int>> dp(n, vector<int>(total + 1, -1));
  return helper(arr, total, 0, n - 1, dp);
}

int helper(vector<int> &arr, int total, int sum1, int idx, vector<vector<int>> &dp)
{
  if (idx == -1)
    return abs(total - sum1);
  if (dp[idx][total] != -1)
    return dp[idx][total];

  int pick = helper(arr, total, sum1, idx - 1, dp);
  int notPick = helper(arr, total - arr[idx], sum1 + arr[idx], idx - 1, dp);

  return dp[idx][total] = min(pick, notPick);
}
