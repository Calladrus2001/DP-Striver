#include <bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{
  int helper(vector<vector<int>> & arr, int i, int j, vector<vector<int>> &dp);
  vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
  int maxi = -1e9;
  for (int j = 0; j < matrix[0].size(); j++)
  {
    int ans = helper(matrix, matrix.size() - 1, j, dp);
    maxi = max(maxi, ans);
  }

  return maxi;
}

int helper(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dp)
{
  if (j < 0 || j > arr[0].size() - 1)
    return -1e9;
  if (i == 0)
    return arr[i][j];
  if (dp[i][j] != -1)
    return dp[i][j];

  int diagLeft = arr[i][j] + helper(arr, i - 1, j - 1, dp);
  int up = arr[i][j] + helper(arr, i - 1, j, dp);
  int diagRight = arr[i][j] + helper(arr, i - 1, j + 1, dp);

  return dp[i][j] = max(diagLeft, max(up, diagRight));
}