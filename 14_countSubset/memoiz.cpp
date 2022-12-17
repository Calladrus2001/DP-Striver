#include <bits/stdc++.h>
int findWays(vector<int> &num, int tar)
{
  vector<vector<int>> dp(num.size(), vector<int>(tar + 1, -1));
  int helper(vector<int> & num, int target, int idx, vector<vector<int>> &dp);
  return helper(num, tar, num.size() - 1, dp);
}

int helper(vector<int> &num, int target, int idx, vector<vector<int>> &dp)
{
  if (idx == 0)
  {
    if (target == 0 && num[idx] == 0)
      return 2;
    if (target == 0 || target == num[idx])
      return 1;
    return 0;
  }
  if (target < 0)
    return 0;
  if (idx < 0)
    return 0;

  if (dp[idx][target] != -1)
    return dp[idx][target];

  int notPick = helper(num, target, idx - 1, dp);
  int pick = helper(num, target - num[idx], idx - 1, dp);

  return dp[idx][target] = pick + notPick;
}