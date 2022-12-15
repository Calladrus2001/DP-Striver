#include <bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid)
{
  int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp);
  int i = grid.size();
  int j = grid[0].size();
  vector<vector<int>> dp(i, vector<int>(j, -1));
  return helper(i - 1, j - 1, grid, dp);
}

int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
  if (i == 0 && j == 0)
    return grid[0][0];
  if (i < 0 || j < 0)
    return 65525;
  if (dp[i][j] != -1)
    return dp[i][j];

  int up = helper(i - 1, j, grid, dp) + grid[i][j];
  int left = helper(i, j - 1, grid, dp) + grid[i][j];

  return dp[i][j] = min(up, left);
}