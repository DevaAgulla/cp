#include<bits/stdc++.h>
using namespace std;


class minSGTree{
   vector<int> sg;
   public:
     minSGTree(int n){
     sg.resize(4*n+1);
   }
   
   void build(int ind ,int low ,int high,int arr[]){
      if(low==high){
          sg[ind] = low;
          return ;
      }
      
      int mid = (low+high) >> 1;
      build(2*ind+1,low,mid,arr);
      build(2*ind+2,mid+1,high,arr);
      //sg[ind] = min(sg[2*ind+1],sg[2*ind+2]);
      if(arr[sg[2*ind+1]] < arr[sg[2*ind+2]]){
         sg[ind] = sg[2*ind+1];
      }
      else{
         sg[ind] = sg[2*ind+2];
      }
   }
   //get minimum element in a range
   int query(int ind ,int low,int high,int l,int r,int arr[]){
      //non overlap 
      // l r low high  or low high l r
      if(r < low or l > high) return -1;
      // complete overlap
      // l low high r
      if(low >= l and high <=r) return sg[ind];
      
      int mid = (high+low) >> 1;
      int left = query(2*ind+1,low,mid,l,r,arr);
      int right = query(2*ind+2,mid+1,high,l,r,arr);
      //return min(left,right);
      if(left==-1) return right;
      if(right==-1) return left;
      if(arr[left] < arr[right]){
         return left;
      }
      return right;
   }
  
};

class maxSGTree{
   vector<int> sg;
   public:
    maxSGTree(int n){
     sg.resize(4*n+1);
   }
   
   void build(int ind ,int low ,int high,int arr[]){
      if(low==high){
          sg[ind] = low;
          return ;
      }
      
      int mid = (low+high) >> 1;
      build(2*ind+1,low,mid,arr);
      build(2*ind+2,mid+1,high,arr);
      //sg[ind] = min(sg[2*ind+1],sg[2*ind+2]);
      if(arr[sg[2*ind+1]] > arr[sg[2*ind+2]]){
         sg[ind] = sg[2*ind+1];
      }
      else{
         sg[ind] = sg[2*ind+2];
      }
   }
   //get minimum element in a range
   int query(int ind ,int low,int high,int l,int r,int arr[]){
      //non overlap 
      // l r low high  or low high l r
      if(r < low or l > high) return -1;
      // complete overlap
      // l low high r
      if(low >= l and high <=r) return sg[ind];
      
      int mid = (high+low) >> 1;
      int left = query(2*ind+1,low,mid,l,r,arr);
      int right = query(2*ind+2,mid+1,high,l,r,arr);
      //return min(left,right);
      if(left==-1) return right;
      if(right==-1) return left;
      if(arr[left] > arr[right]){
         return left;
      }
      return right;
   }
  
};

int main(){
  int t;
  cin >> t;
  while(t--){
     int n;
     cin >> n;
     int arr[n];
     for(int i=0;i<n;i++) cin >> arr[i];
     minSGTree t1 = minSGTree(n);
     t1.build(0,0,n-1,arr);
     maxSGTree t2 = maxSGTree(n);
     t2.build(0,0,n-1,arr);
     
     int q;
     cin >> q;
     while(q--){
       int l,r;
       cin >> l >> r;
       l--,r--;
       int one = t1.query(0,0,n-1,l,r,arr);
       int two = t2.query(0,0,n-1,l,r,arr);
       if(arr[one] ==arr[two])
         cout << -1 << " " << -1 << endl;
       else cout << one+1 << " " << two+1 << endl;
     }
  }

}
