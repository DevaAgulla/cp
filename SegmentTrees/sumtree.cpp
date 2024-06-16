class SGTree{
   vector<int> sg;
   public:
    SGTree(int n){
     sg.resize(4*n+1);
   }
   
   void build(int ind ,int low ,int high,vector<int> &arr){
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
          sg[ind] = val;return ;
      }
      
      int mid = (low+high) >>1;
      if(i <= mid)  update(2*ind+1,low,mid,i,val);
      else update(2*ind+2,mid+1,high,i,val);
      
      sg[ind] = sg[2*ind+1]+sg[2*ind+2];
   }

};
