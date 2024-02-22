 int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int maxi = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j] < arr[i] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                }
                else if(arr[j] < arr[i] and dp[j]+1==dp[i]){
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(dp[i],maxi);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)ans+=cnt[i];
        }
        return ans;
    }
