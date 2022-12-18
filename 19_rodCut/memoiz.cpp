#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
  vector<vector<int>> dp(n, vector<int>(n + 1, -1));
  int helper(vector<int> & price, int idx, int length, vector<vector<int>> &dp);
  return helper(price, n - 1, n, dp);
}

int helper(vector<int> &price, int idx, int len, vector<vector<int>> &dp)
{
  if (idx == 0)
  {
    return len * price[0];
  }
  if (dp[idx][len] != -1)
    return dp[idx][len];

  int pick = -1e9;
  if (len >= idx + 1)
    pick = price[idx] + helper(price, idx, len - (idx + 1), dp);
  int notPick = helper(price, idx - 1, len, dp);

  return dp[idx][len] = max(pick, notPick);
}
