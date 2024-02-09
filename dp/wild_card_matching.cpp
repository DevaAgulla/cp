bool wildcardMatching(string s, string t)
{
   int n=s.size();
   int m = t.size();
   vector<vector<int>> dp(n+1,vector<int>(m+1,0));
   dp[0][0] = 1;
   for(int i=1;i<=m;i++) dp[0][i] = 0;
   int k=1;
   while(s[k-1]=='*'){
      for(int j=0;j<=m;j++) dp[k][j]=1;k++;
   }

   for(int i=k;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(s[i-1]=='*'){
            dp[i][j] = dp[i-1][j] or dp[i][j-1];
         }
         else if(s[i-1]=='?' or s[i-1]==t[j-1]){
           dp[i][j] = dp[i-1][j-1];
         }
         else dp[i][j] = 0;
      }
   }
  return dp[n][m];
}
