int trap(vector<int>& arr) {
        int n = arr.size();
        int a=0,b=n-1;
        int lm = 0,rm =0;
        int ans =0;
        while(a<=b){
            lm = max(lm,arr[a]);
            rm = max(rm,arr[b]);
            if(lm < rm){
                ans+=(lm-arr[a]);
                a++;
            }
            else{
                ans+=(rm-arr[b]);
                b--;
            }
        }
        return ans;
    }
