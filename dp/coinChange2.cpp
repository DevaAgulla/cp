#include<bits/stdc++.h>

long countWaysToMakeChange(int *arr, int n, int val)
{
    vector<vector<long>> dp(n,vector<long>(val+1,0));
    for(int i=0;i<=val;i++) dp[0][i] = i%arr[0]==0;
    for(int i=1;i<n;i++){
        for(int tar=0;tar<=val;tar++){
            long notake = dp[i-1][tar];
            long take = 0;
            if(arr[i] <= tar) take = dp[i][tar-arr[i]];
            dp[i][tar] = notake+take;
        }
    }   
    return dp[n-1][val];
}
