#include <bits/stdc++.h>
using namespace std;

// Max sum of non adjacent elements

int f(vector<int> &arr)
{
  int helper(vector<int> & arr, int idx, int sum);
  int maxNum = helper(arr, arr.size() - 1, 0);
  return maxNum;
}

int helper(vector<int> &arr, int idx, int sum)
{
  if (idx == 0)
    return sum + arr[idx];
  if (idx < 0)
    return 0;

  int pick = helper(arr, idx - 2, sum + arr[idx]);
  int notPick = helper(arr, idx - 1, sum);
  return max(pick, notPick);
}

int main()
{
  vector<int> heights = {7, 4, 4, 2, 6, 6, 3, 4};
  cout << f(heights) << endl;
}