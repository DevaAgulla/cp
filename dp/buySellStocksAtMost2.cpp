int f(int ind ,int cap,vector<int>& prices,int n,vector<vector<int>> &dp) {
   if(ind==n or cap==4) return 0;
   if(cap%2==0){
       return dp[ind][cap] = max(-prices[ind]+f(ind+1,cap+1,prices,n,dp)
       ,f(ind+1,cap,prices,n,dp));
   }
   return dp[ind][cap] = max(prices[ind]+f(ind+1,cap+1,prices,n,dp)
       ,f(ind+1,cap,prices,n,dp));
}

int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(5,0));
    for(int i=0;i<4;i++)dp[n][i] = 0;
    for(int i=0;i<n;i++)dp[i][4] = 0;
    for(int ind=n-1;ind>=0;ind--){
        for(int cap=3;cap>=0;cap--){
            if(cap%2==0)
              dp[ind][cap] = max(-prices[ind]+dp[ind+1][cap+1],dp[ind+1][cap]);
            else
               dp[ind][cap] = max(prices[ind]+dp[ind+1][cap+1],dp[ind+1][cap]);
        }
    }

    return dp[0][0];
}
