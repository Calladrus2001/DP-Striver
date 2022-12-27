#include <bits/stdc++.h>

class Solution
{
public:
  int numDistinct(string s, string t)
  {
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return helper(s, t, 0, 0, dp);
  }

  int helper(string &s, string &t, int idx1, int idx2, vector<vector<int>> &dp)
  {
    if (idx2 == t.size())
      return 1;
    if (idx1 == s.size())
      return 0;
    if (dp[idx1][idx2] != -1)
      return dp[idx1][idx2];

    if (s[idx1] == t[idx2])
      return dp[idx1][idx2] = helper(s, t, idx1 + 1, idx2 + 1, dp) + helper(s, t, idx1 + 1, idx2, dp);
    else
      return dp[idx1][idx2] = helper(s, t, idx1 + 1, idx2, dp);
  }
};