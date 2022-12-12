#include <bits/stdc++.h>
using namespace std;

// frog jump

int frogJump(int n, vector<int> &heights, vector<int> &dp)
{
  if (n == 1)
    return 0;
  if (dp[n - 1] != -1)
    return dp[n - 1];
  int left = frogJump(n - 1, heights, dp) + abs(heights[n - 1] - heights[n - 2]);
  int right = INT_MAX;
  if (n > 2)
    right = frogJump(n - 2, heights, dp) + abs(heights[n - 1] - heights[n - 3]);
  return dp[n - 1] = min(left, right);
}
int main()
{
  int n = 8;
  vector<int> dp(n, -1);
  vector<int> heights = {7, 4, 4, 2, 6, 6, 3, 4};
  cout << frogJump(n, heights, dp) << endl;
}