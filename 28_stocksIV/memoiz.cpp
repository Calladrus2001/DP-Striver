#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int> Arr, int ind, int buy, int n, vector<vector<int>> &dp ){
    if(ind>=n) return 0; 
    if(dp[ind][buy]!=-1) eturn dp[ind][buy];
    int profit;
    
    if(buy==0){
        profit = max(0+getAns(Arr,ind+1,0,n,dp), -Arr[ind]+getAns(Arr,ind+1,1,n,dp));
    }
    if(buy==1){
        profit = max(0+getAns(Arr,ind+1,1,n,dp), Arr[ind]+getAns(Arr,ind+2,0,n,dp));
    }
    return dp[ind][buy] = profit;
}

int stockProfit(vector<int> &Arr)
{
    int n = Arr.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));    
    int ans = getAns(Arr,0,0,n,dp);
    return ans;
}
