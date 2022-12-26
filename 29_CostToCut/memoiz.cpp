#include <bits/stdc++.h> 
int cost(int n, int c, vector<int> &cuts){
    int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp);
    vector<vector<int>> dp (n+1, vector<int>(c+1, -1));
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    return helper(1, c, cuts, dp);
}

int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    for (int idx = i; idx <= j; idx ++){
        int cost = cuts[j+1] - cuts[i-1] + helper(i, idx - 1, cuts, dp) + helper(idx + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
