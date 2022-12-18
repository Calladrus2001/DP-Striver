#include <bits/stdc++.h>
int targetSum(int n, int target, vector<int> &arr)
{
  int helper(vector<int> & arr, int sum, int idx, vector<vector<int>> &dp);
  int total = 0;
  for (int i = 0; i < n; i++)
    total += arr[i];

  if (total - target < 0)
    return 0;
  if ((total - target) % 2 == 1)
    return 0;
  int sum = (total - target) / 2;

  vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
  return helper(arr, sum, n - 1, dp);
}

int helper(vector<int> &arr, int sum, int idx, vector<vector<int>> &dp)
{
  if (idx == 0)
  {
    if (sum == 0 && arr[idx] == 0)
      return 2;
    if (sum == 0 || sum == arr[idx])
      return 1;
    return 0;
  }
  if (dp[idx][sum] != -1)
    return dp[idx][sum];

  int pick = 0;
  if (arr[idx] <= sum)
    pick = helper(arr, sum - arr[idx], idx - 1, dp);
  int notPick = helper(arr, sum, idx - 1, dp);

  return dp[idx][sum] = pick + notPick;
}
