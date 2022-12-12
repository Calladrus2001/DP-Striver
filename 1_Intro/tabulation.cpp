#include <iostream>
#include <vector>
using namespace std;

// fibo using dp

int fibo(int n, vector<int> &dp)
{
  if (n <= 1)
    return n;
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int main()
{
  int n = 7;
  vector<int> dp(n, -1);
  cout << fibo(n - 1, dp) << endl;
}

// TC = O(n)
// SC = O(n) for array