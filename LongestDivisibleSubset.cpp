vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int last = 0;
        int maxi = 1;
        vector<int> hash(n);
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 and dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                last = i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[last]);
        while(last!=hash[last]){
            last = hash[last];
            ans.push_back(arr[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
