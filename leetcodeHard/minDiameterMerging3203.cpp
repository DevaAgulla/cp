class Solution {
public:
    vector<vector<int>> makeGraph(vector<vector<int>>& edges){
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        for(int i=0;i<n;i++){
           int u = edges[i][0];
           int v = edges[i][1];
           graph[u].push_back(v);
           graph[v].push_back(u);
        }
        return graph;
    }
    void dfs(int node,int par,vector<vector<int>>& g,pair<int,int>& res,int dis){

        if(dis > res.first){
            res = {dis,node};
        }
        for(auto it:g[node]){
            if(it!=par){
                dfs(it,node,g,res,dis+1);
            }
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> g1 = makeGraph(edges1);
        vector<vector<int>> g2 = makeGraph(edges2);
        pair<int,int> res1 = {INT_MIN,-1};
        pair<int,int> res2 = {INT_MIN,-1};
        dfs(0,-1,g1,res1,0);
        dfs(res1.second,-1,g1,res1,0);
        dfs(0,-1,g2,res2,0);
        dfs(res2.second,-1,g2,res2,0);
        int d1 = res1.first;
        int d2 = res2.first;
        return max({d1,d2,(d1+1)/2 + (d2+1)/2 +1});
    }
};
