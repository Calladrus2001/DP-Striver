#include <bits/stdc++.h>
int canYouMake(string &str, string &ptr)
{
  int lcs(string s, string t);
  int common = lcs(str, ptr);
  int m = str.length() - common;
  int n = ptr.length() - common;
  return m + n;
}

int lcs(string s, string t)
{
  int helper(int idx1, int idx2, string s1, string s2, vector<vector<int>> &dp);
  int s1 = s.length();
  int s2 = t.length();
  vector<vector<int>> dp(s1, vector<int>(s2, -1));
  return helper(s1 - 1, s2 - 1, s, t, dp);
}

int helper(int idx1, int idx2, string s1, string s2, vector<vector<int>> &dp)
{
  if (idx1 < 0 || idx2 < 0)
    return 0;
  if (dp[idx1][idx2] != -1)
    return dp[idx1][idx2];

  if (s1[idx1] == s2[idx2])
    return 1 + helper(idx1 - 1, idx2 - 1, s1, s2, dp);
  else
    return dp[idx1][idx2] = max(helper(idx1 - 1, idx2, s1, s2, dp), helper(idx1, idx2 - 1, s1, s2, dp));
}