#include <bits/stdc++.h>

int countWaysUtil(int i, int j, vector<vector<int>> &dp)
{
  if (i == 0 && j == 0)
    return 1;
  if (i < 0 || j < 0)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];

  int up = countWaysUtil(i - 1, j, dp);
  int left = countWaysUtil(i, j - 1, dp);

  return dp[i][j] = up + left;
}

int uniquePaths(int m, int n)
{
  int countWaysUtil(int i, int j, vector<vector<int>> &dp);
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return countWaysUtil(m - 1, n - 1, dp);
}
