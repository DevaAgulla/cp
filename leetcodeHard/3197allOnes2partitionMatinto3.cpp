class Solution {
public:
    int one(vector<vector<int>>& mat,int x,int y,int n,int m){
        int top = n;
        int left = m;
        int down = x;
        int right = y;
        int f = 0;
        for(int i=x;i<n;i++){
            for(int j=y;j<m;j++){
                if(mat[i][j]==1){
                    top = min(i,top);
                    left = min(j,left);
                    down = max(i,down);
                    right = max(j,right);
                    f++;
                }
            }
        }
        if(f==0) return 0;
        return (down-top+1)*(right-left+1);
    }

    int two(vector<vector<int>>& mat,int x,int y,int n,int m){
        int ans = INT_MAX;
        for(int i=x;i<n;i++){
            int a = one(mat,x,y,i,m);
            int b = one(mat,i,y,n,m);
            ans = min(ans,a+b);
        }
        for(int j=y;j<m;j++){
            int a = one(mat,x,y,n,j);
            int b = one(mat,x,j,n,m);
            ans = min(ans,a+b);
        }
        return ans;
    }
    int minimumSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
             int a = one(mat,0,0,i,m);
            int b = two(mat,i,0,n,m);
             ans = min(ans,a+b);
               a = two(mat,0,0,i,m);
             b = one(mat,i,0,n,m);
             ans = min(ans,a+b);
        }

        for(int j=1;j<m;j++){
            int a = one(mat,0,0,n,j);
            int b = two(mat,0,j,n,m);
            ans = min(ans,a+b);
             a = two(mat,0,0,n,j);
             b = one(mat,0,j,n,m);
            ans = min(ans,a+b);
        }
        return ans;
    }
};
