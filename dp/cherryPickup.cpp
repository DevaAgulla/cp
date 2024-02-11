class Solution {
public:
   int f(int i,int j1,int j2,vector<vector<int>>& grid,int n,int m,vector<vector<vector<int>>> &dp){
       if(j1<0 or j2<0) return INT_MIN;
       if(j1 >=m or j2 >=m) return INT_MIN;
       if(i==n-1){
           if(j1==j2) return grid[i][j1];
           return grid[i][j1]+grid[i][j2];
       }
       if(dp[i][j1][j2] != -1) return dp[i][j1][j2] ;
       int maxi = INT_MIN;
       for(int k1=-1;k1<=1;k1++){
           for(int k2=-1;k2<=1;k2++){
               int ans;
              if(j1==j2) ans = grid[i][j1]+f(i+1,j1+k1,j2+k2,grid,n,m,dp);
              else ans = grid[i][j1]+grid[i][j2]+f(i+1,j1+k1,j2+k2,grid,n,m,dp);
              maxi = max(maxi,ans);
           }
       }
       return dp[i][j1][j2] = maxi;
       
   }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1]+grid[n-1][j2];
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi = INT_MIN;
                    for(int k1=-1;k1<=1;k1++){
                       for(int k2=-1;k2<=1;k2++){
                           int ans;
                           if(j1+k1 >= 0 and j1+k1<m and j2+k2 >= 0 and j2+k2<m){
                               if(j1==j2) ans = grid[i][j1]+dp[i+1][j1+k1][j2+k2];
                               else ans = grid[i][j1]+grid[i][j2]+dp[i+1][j1+k1][j2+k2];;
                               maxi = max(maxi,ans);
                           } 
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};
