 int minPatches(vector<int>& nums, int n) {
        long long maxnumber = 0;
        int ans = 0;
        int i=0;
        while(maxnumber < n){
            if(i<nums.size() and maxnumber+1>=nums[i]){
                maxnumber+=nums[i];
                i++;
            }else{
                maxnumber+=maxnumber+1;
                ans++;
            }
        }
        return ans;
    }
