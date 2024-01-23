#include<bits/stdc++.h>
using namespace std;

class SGTree{
  vector<int> seg,lazy;
  public:
    SGTree(int n){
       seg.resize(4*n);
       lazy.resize(4*n);
    }
    
  public:
    void build(int ind,int low,int high,int arr[]){
      if(low==high){
         seg[ind] = arr[low]; return;
      }
      int mid = (low+high) >> 1;
      build(2*ind+1,low,mid,arr);
      build(2*ind+2,mid+1,high,arr);
      seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    
  public:
    void update(int ind,int low,int high,int l,int r,int val){
        //complete overlap --> update and lazy propagate
        // no overlap --> nothing
        //partial overlap 
        
        
        //updates the lazy
        
        if(lazy[ind] !=0 ){
           seg[ind]+=(high-low+1) * lazy[ind];
           if(low != high){
              lazy[2*ind+1] += lazy[ind];
              lazy[2*ind+2] +=lazy[ind];
           }
           lazy[ind] = 0;
        }
        
        //no overlap l r  low high  or low high l r
        if(r < low or high < l) return ;
        
        //complete overlap  l low high r
        if(low >=l and high <= r){
           seg[ind] += (high-low+1)*val;
           if(low!=high){
              lazy[2*ind+1]+=val;
              lazy[2*ind+2]+=val;
           }
           return ;
        }
        
        //partail overlap
        int mid = (low+high) >> 1;
        update(2*ind+1,low,mid,l,r,val);
        update(2*ind+2,mid+1,high,l,r,val);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    
  public:
    int query(int ind ,int low,int high,int l ,int r){
        //updates the lazy 
        if(lazy[ind] !=0 ){
           seg[ind]+=(high-low+1) * lazy[ind];
           if(low != high){
              lazy[2*ind+1] += lazy[ind];
              lazy[2*ind+2] +=lazy[ind];
           }
           lazy[ind] = 0;
        }
        //no overlap
        if(r< low or high < l ) return 0;
        //overlap 
        if(low>=l and high<=r) return seg[ind];
        
        //partial overlap
        int mid = (low+high)/2;
        int left = query(2*ind+1,low ,mid,l,r);
        int right = query(2*ind+2,mid+1,high,l,r);
        return left+right;
    }
};

int main(){
    int n; 
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    SGTree t1 = SGTree(n);
    t1.build(0,0,n-1,arr);
    int q;
    cin >> q;
    while(q--){
       int type;
       cin >> type;
       if(type==1){
         int l,r;
         cin >> l >> r;
         cout << t1.query(0,0,n-1,l,r);       
       }
       else{
          int l,r,val;
          cin >> l >> r >> val;
          t1.update(0,0,n-1,l,r,val);
       }
    }
}
