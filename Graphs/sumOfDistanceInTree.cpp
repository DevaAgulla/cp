class Solution {
public:
    void dfs(int par,int node ,vector<vector<int>> &grap,vector<int>&ans,vector<int>&ct){
        for(auto it: grap[node]){
            if(it!=par){
                dfs(node,it,grap,ans,ct);
                ct[node]+=ct[it];
                ans[node]+=ct[it]+ans[it];
            }
        }
    }
    void dfs2(int par,int node ,vector<vector<int>> &grap,vector<int>&ans,vector<int>&ct){
        for(auto it: grap[node]){
            if(it!=par){
                ans[it]= ans[node]-ct[it]+(grap.size()-ct[it]);
                dfs2(node,it,grap,ans,ct);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& arr) {
        vector<vector<int>> grap(n);
        for(int i=0;i<n-1;i++){
            int u = arr[i][0];
            int v = arr[i][1];
            grap[u].push_back(v);
            grap[v].push_back(u);
        }
        vector<int> ct(n,1);
        vector<int> ans(n,0);
        dfs(-1,0,grap,ans,ct);
        dfs2(-1,0,grap,ans,ct);
        return ans;
    }
};
