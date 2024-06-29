int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int high = accumulate(nums.begin(),nums.end(),0);
        int low = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            int pos = 0;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(cnt+nums[i]>mid){
                    pos++;
                    cnt = 0;
                }
                cnt+=nums[i];
            }
            if(cnt)pos++;
            if(pos<=k){
                ans = min(ans,mid);
                high =mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
