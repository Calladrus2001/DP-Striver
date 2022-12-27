#include <bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2)
{
  vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), -1));
  int helper(string s1, string s2, int i1, int i2, vector<vector<int>> &dp);
  return helper(str1, str2, str1.size() - 1, str2.size() - 1, dp);
}

int helper(string s1, string s2, int i1, int i2, vector<vector<int>> &dp)
{
  if (i1 < 0)
    return i2 + 1;
  if (i2 < 0)
    return i1 + 1;
  if (dp[i1][i2] != -1)
    return dp[i1][i2];

  if (s1[i1] == s2[i2])
    return dp[i1][i2] = helper(s1, s2, i1 - 1, i2 - 1, dp);
  else
    return dp[i1][i2] = min(
               1 + helper(s1, s2, i1, i2 - 1, dp),
               min(1 + helper(s1, s2, i1 - 1, i2, dp), 1 + helper(s1, s2, i1 - 1, i2 - 1, dp)));
}