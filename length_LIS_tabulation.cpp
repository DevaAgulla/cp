 int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1);
        int ans = 0;
        for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
               if(arr[i] > arr[j]){
                   dp[i] = max(dp[i],1+dp[j]);
               }
           }
           ans = max(ans,dp[i]);
        }
        return ans;
    }
