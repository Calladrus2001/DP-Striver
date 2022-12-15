#include <bits/stdc++.h>
using namespace std;

// Ninja Training

int main()
{
  int f(vector<vector<int>> & points, int day, int last, int score, vector<int> &dp);
  vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
  vector<int> dp(points.size(), -1);
  cout << f(points, points.size() - 1, -1, 0, dp) << endl;
}

int f(vector<vector<int>> &points, int day, int last, int score, vector<int> &dp)
{
  if (day == 0)
  {
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    return score + maxi;
  }
  if (dp[day] != -1)
    return dp[day];
  int a0, a1, a2 = -1;
  if (a0 != last)
    a0 = f(points, day - 1, 0, score + points[day][0], dp);
  if (a1 != last)
    a1 = f(points, day - 1, 1, score + points[day][1], dp);
  if (a2 != last)
    a2 = f(points, day - 1, 2, score + points[day][2], dp);

  return dp[day] = max(a0, max(a1, a2));
}