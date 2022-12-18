#include <bits/stdc++.h>

long countWaysToMakeChangeHelper(int denominations[], int value, int n, vector<vector<long>> &memo)
{
  if (value == 0)
    return 1;
  if (n < 0 || value < 0)
    return 0;
  if (memo[value][n] != -1)
    return memo[value][n];

  long incl = countWaysToMakeChangeHelper(denominations, value - denominations[n], n, memo);
  long excl = countWaysToMakeChangeHelper(denominations, value, n - 1, memo);

  memo[value][n] = incl + excl;

  return memo[value][n];
}

long countWaysToMakeChange(int denominations[], int n, int value)
{
  vector<vector<long>> memo(value + 1, vector<long>(n + 1, -1));
  return countWaysToMakeChangeHelper(denominations, value, n - 1, memo);
}