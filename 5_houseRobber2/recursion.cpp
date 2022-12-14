#include <bits/stdc++.h>
using namespace std;

// House Robber 2

int main()
{
  int f(vector<int> & arr);
  vector<int> houses = {1, 3, 2, 1};
  cout << f(houses) << endl;
}

int f(vector<int> &arr)
{
  int maxVal(vector<int> & arr, int idx, int sum);
  vector<int> temp1, temp2;
  if (arr.size() == 1)
    return arr[0];

  for (int i = 0; i < arr.size(); i++)
  {
    if (i != 0)
      temp1.push_back(arr[i]);
    if (i != arr.size() - 1)
      temp2.push_back(arr[i]);
  }
  return max(maxVal(temp1, temp1.size() - 1, 0), maxVal(temp2, temp2.size() - 1, 0));
}

int maxVal(vector<int> &arr, int idx, int sum)
{
  if (idx == 0)
    return sum + arr[0];
  if (idx < 0)
    return 0;

  int pick = maxVal(arr, idx - 2, sum + arr[idx]);
  int notPick = maxVal(arr, idx - 1, sum);
  return max(pick, notPick);
}