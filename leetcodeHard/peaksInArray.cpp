#include<bits/stdc++.h>
using namespace std;


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


class Solution {
public:
    vector<int> countOfPeaks(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        SGTree tree = SGTree(n);
        vector<int>temp(n,0);
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1])temp[i] = 1;
        }
        tree.build(0,0,n-1,temp);
        vector<int> ans;
        for(int i=0;i<q.size();i++){
            int t=q[i][0];
            if(t==1){
                int l=q[i][1];
                int r=q[i][2];
                if(r-l<=1)ans.push_back(0);
                else ans.push_back(tree.query(0,0,n-1,l+1,r-1));
            }
            else{
                int ind = q[i][1];
                int val = q[i][2];
                arr[ind] = val;
                for(int i=ind-1;i<=ind+1;i++){
                    if(i>0 and i<n-1){
                        if(arr[i]>arr[i-1] and arr[i]>arr[i+1])tree.update(0,0,n-1,i,1);
                        else tree.update(0,0,n-1,i,0);
                    }
                }
            }
        }
        return ans;
    }
};
