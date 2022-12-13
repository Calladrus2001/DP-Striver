#include <bits/stdc++.h>
using namespace std;

// frog jump with K Distance

int frogJump(int n, vector<int> &heights, vector<int> &dp, int k)
{
  if (n == 0)
    return 0;
  int minJmp = INT_MAX;
  for (int i = 1; i <= k; i++)
  {
    if (n - i >= 0)
    {
      int jump = frogJump(n - i, heights, dp, k) + abs(heights[n] - heights[n - i]);
      minJmp = min(jump, minJmp);
    }
  }
  return minJmp;
}
int main()
{
  int n = 8;
  vector<int> dp(n, -1);
  int k = 5;
  vector<int> heights = {7, 4, 4, 2, 6, 6, 3, 4};
  cout << frogJump(n - 1, heights, dp, k) << endl;
}