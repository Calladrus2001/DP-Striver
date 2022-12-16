#include <bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{
  int helper(vector<vector<int>> & arr, int i, int j);
  int maxi = -1e9;
  for (int j = 0; j < matrix[0].size(); j++)
  {
    int ans = helper(matrix, matrix.size() - 1, j);
    maxi = max(maxi, ans);
  }

  return maxi;
}

int helper(vector<vector<int>> &arr, int i, int j)
{
  if (j < 0 || j > arr[0].size() - 1)
    return -1e9;
  if (i == 0)
    return arr[i][j];

  int diagLeft = arr[i][j] + helper(arr, i - 1, j - 1);
  int up = arr[i][j] + helper(arr, i - 1, j);
  int diagRight = arr[i][j] + helper(arr, i - 1, j + 1);

  return max(diagLeft, max(up, diagRight));
}