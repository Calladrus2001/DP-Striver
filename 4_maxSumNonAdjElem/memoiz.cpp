#include <bits/stdc++.h>
using namespace std;

// Max sum of non adjacent elements

int f(vector<int> &arr, vector<int> &dp)
{
  int helper(vector<int> & arr, int idx, int sum, vector<int> &dp);
  int maxNum = helper(arr, arr.size() - 1, 0, dp);
  return maxNum;
}

int helper(vector<int> &arr, int idx, int sum, vector<int> &dp)
{
  if (idx == 0)
    return sum + arr[idx];
  if (idx < 0)
    return 0;
  if (dp[idx] != -1)
    return dp[idx];

  int pick = helper(arr, idx - 2, sum + arr[idx], dp);
  int notPick = helper(arr, idx - 1, sum, dp);
  return dp[idx] = max(pick, notPick);
}

int main()
{
  vector<int> heights = {7, 4, 4, 2, 6, 6, 3, 4};
  vector<int> dp(heights.size(), -1);
  cout << f(heights, dp) << endl;
}