#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr)
{
  vector<int> dp(n, -1);
  bool helper(int i, int k, vector<int> &arr, vector<int> &dp);
  return helper(n - 1, k, arr, dp);
}

bool helper(int i, int k, vector<int> &arr, vector<int> &dp)
{
  if (k == 0)
    return true;
  if (k < 0 || i < 0)
    return false;

  bool pick = helper(i - 1, k - arr[i], arr, dp);
  bool notPick = helper(i - 1, k, arr, dp);

  return pick | notPick;
}