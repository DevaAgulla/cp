 int cntPairsLessthanK(int k,vector<int>& arr){
        int ans = 0;
        int j=0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            while(j<n and (arr[j]-arr[i])<=k)j++;
            ans+=(j-i-1);
        }
        return ans;
    }
    int smallestDistancePair(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int low = 0;
        int high = arr[n-1]-arr[0];
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            int cnt = cntPairsLessthanK(mid,arr);
            if(cnt >= k){
                ans = mid; 
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
