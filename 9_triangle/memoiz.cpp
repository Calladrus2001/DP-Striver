#include <bits/stdc++.h>
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
  vector<vector<int>> dp(n, vector<int>(n, -1));
  int helper(vector<vector<int>> & arr, int n, int i, int j, vector<vector<int>> dp);
  return helper(triangle, n, 0, 0, dp);
}

int helper(vector<vector<int>> &arr, int n, int i, int j, vector<vector<int>> dp)
{
  if (i == n - 1)
    return arr[i][j];
  if (dp[i][j] != -1)
    return dp[i][j];

  int way1 = helper(arr, n, i + 1, j, dp) + arr[i][j];
  int way2 = helper(arr, n, i + 1, j + 1, dp) + arr[i][j];

  return dp[i][j] = min(way1, way2);
}