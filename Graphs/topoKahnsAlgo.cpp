 vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<int> indegree(n,0);
        vector<int> ans;
        vector<int> adj[n];
        for(int i=0;i<arr.size();i++){
            int u = arr[i][0];
            int v = arr[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> qe;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) qe.push(i);
        }
        while(!qe.empty()){
            int node = qe.front();
            qe.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)qe.push(it);
            }
        }
        if(ans.size() < n) return {};
        return ans;
    }
