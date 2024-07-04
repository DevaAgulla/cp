class Solution{
    public:
    int maxSweetness(vector<int>& nums, int N, int k) {
    // Write your code here.
    int n = nums.size();
    k++;
        int high = accumulate(nums.begin(),nums.end(),0);
        int low = *min_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            int pos = 0;
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(cnt+nums[i]>=mid){
                    pos++;
                    cnt = 0;
                }
                else cnt+=nums[i];
            }
            if(cnt>=mid)pos++;
            if(pos>=k){
                ans = mid;
                low = mid+1;
            }
            else high =mid-1;
        }
        return ans;
    }
};
