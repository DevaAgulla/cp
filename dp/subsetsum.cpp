#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++)dp[i][0] = 1;
    if(arr[0]<=k) dp[0][arr[0]] = 1;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            int notake = dp[i-1][j];
            int take = 0;
            if(arr[i] <= j)take = dp[i-1][j-arr[i]];
            dp[i][j] = take or notake;
        }
    }
    return dp[n-1][k];

}
