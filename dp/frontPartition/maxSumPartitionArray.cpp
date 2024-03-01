class Solution {
public:
    int getCost(int i,int j,vector<int>& arr){
        int m = INT_MIN;
        for(int k=i;k<=j;k++) m = max(m,arr[k]);
        return m*(j-i+1);
    }
    int f(int i,vector<int>& arr,int n,int k, vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi = INT_MIN;
        for(int j=i;j<i+k;j++){
            if(j < n){
                int cost = getCost(i,j,arr) + f(j+1,arr,n,k,dp);
                maxi = max(maxi,cost);
            }
        }
        return dp[i] =  maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxi = INT_MIN;
            for(int j=i;j<i+k;j++){
              if(j < n){
                int cost = getCost(i,j,arr) + dp[j+1];
                maxi = max(maxi,cost);
              }
            }
            dp[i] =  maxi;
        }
        return dp[0];
        //return f(0,arr,n,k,dp);
    }
};
