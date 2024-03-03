class SGTree{
   vector<int> sg;
   public:
    SGTree(int n){
     sg.resize(4*n+1);
   }
   
   void build(int ind ,int low ,int high,int arr[]){
      if(low==high){
          sg[ind] = arr[low];
          return ;
      }
      
      int mid = (low+high) >> 1;
      build(2*ind+1,low,mid,arr);
      build(2*ind+2,mid+1,high,arr);
      sg[ind] = sg[2*ind+1]+sg[2*ind+2];
   }
   //get minimum element in a range
   int query(int ind ,int low,int high,int l,int r){
      //non overlap 
      // l r low high  or low high l r
      if(r < low or l > high) return 0;
      // complete overlap
      // l low high r
      if(low >= l and high <=r) return sg[ind];
      
      int mid = (high+low) >> 1;
      int left = query(2*ind+1,low,mid,l,r);
      int right = query(2*ind+2,mid+1,high,l,r);
      return left+right;
   }
   //point updates
   void update(int ind ,int low ,int high,int i,int val){
      if(low==high){
          sg[ind] += val;return ;
      }
      
      int mid = (low+high) >>1;
      if(i <= mid)  update(2*ind+1,low,mid,i,val);
      else update(2*ind+2,mid+1,high,i,val);
      
      sg[ind] = sg[2*ind+1]+sg[2*ind+2];
   }

//update(int ind ,int low ,int high,int i,int val)};

};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        int m=  1e5;
        SGTree t1 = SGTree(m);
        SGTree t2 = SGTree(m);
        vector<int> a(n);
        for(int i=0;i<n;i++){
            a[i] = nums[i];
        }
        sort(a.begin(),a.end());
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int ind = lower_bound(a.begin(),a.end(),nums[0])-a.begin();
        t1.update(0,0,m,ind,1);
        ind  = lower_bound(a.begin(),a.end(),nums[1])-a.begin();
        t2.update(0,0,m,ind,1);
        for(int i=2;i<n;i++){
            int x = nums[i];
            ind = upper_bound(a.begin(),a.end(),x)-a.begin();
            int cnt1 = t1.query(0,0,m,ind,m);
            int cnt2 = t2.query(0,0,m,ind,m);
            if(cnt1 > cnt2){
                arr1.push_back(x);
                int ind2 = lower_bound(a.begin(),a.end(),x)-a.begin();
                t1.update(0,0,m,ind2,1);
            }
            else if(cnt2 > cnt1){
                arr2.push_back(x);
                int ind2 = lower_bound(a.begin(),a.end(),x)-a.begin();
                t2.update(0,0,m,ind2,1);
            }
            else if(arr1.size() <= arr2.size()){
                 arr1.push_back(x);
                int ind2 = lower_bound(a.begin(),a.end(),x)-a.begin();
                t1.update(0,0,m,ind2,1);
            }
            else{
                 arr2.push_back(x);
                int ind2 = lower_bound(a.begin(),a.end(),x)-a.begin();
                t2.update(0,0,m,ind2,1);
            }
        }
        vector<int> res;
        for(int i=0;i<arr1.size();i++) res.push_back(arr1[i]);
        for(int i=0;i<arr2.size();i++) res.push_back(arr2[i]);
        return res;
    }
};
