 int numberOfPermutations(int n, vector<vector<int>>& arr) {
        vector<vector<ll>> dp(n,vector<ll>(401,0));
        dp[0][0] = 1;
        int index = 0;
        sort(arr.begin(),arr.end());
        if(arr[0][0]==0)index++;
        int cnt = arr.back()[1];
        for(int i=1;i<n;i++){
            for(int j=0;j<401;j++){
                for(int k=j;k<min(j+i+1,401);k++){
                    if(dp[i-1][j] >0)dp[i][k]+=dp[i-1][j];
                    dp[i][k] = dp[i][k]%mod;
                }
            }
            if(i==arr[index][0]){
                int cnt2 = arr[index][1];
                for(int j=0;j<401;j++){
                    if(cnt2!=j)dp[i][j]=0;
                }
                index++;
            }
        }
        return dp[n-1][cnt];
    }
