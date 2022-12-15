#include <bits/stdc++.h>
using namespace std;

// Ninja Training

int main()
{
  int f(vector<vector<int>> & points, int day, int last, int score);
  vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
  cout << f(points, points.size() - 1, 3, 0) << endl;
}

int f(vector<vector<int>> &points, int day, int last, int score)
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
  int a0, a1, a2 = -1;
  if (last != 0)
    a0 = f(points, day - 1, 0, score + points[day][0]);
  if (last != 1)
    a1 = f(points, day - 1, 1, score + points[day][1]);
  if (last != 2)
    a2 = f(points, day - 1, 2, score + points[day][2]);

  return max(a0, max(a1, a2));
}