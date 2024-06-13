int findMaxValueOfEquation(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<int,int>>pq;
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            while(!pq.empty() and arr[i][0]-pq.top().second > k) pq.pop();
            if(!pq.empty()) ans = max(ans,arr[i][0]+arr[i][1]+pq.top().first);
            pq.push({arr[i][1]-arr[i][0],arr[i][0]});
        }
        return ans;
    }
