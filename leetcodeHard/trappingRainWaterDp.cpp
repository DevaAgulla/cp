int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = arr[0];
        right[n-1] = arr[n-1];
        for(int i=1;i<n;i++)left[i] = max(arr[i],left[i-1]);
        for(int i=n-2;i>=0;i--) right[i] = max(arr[i],right[i+1]);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-arr[i];
        }
        return ans;
    }
