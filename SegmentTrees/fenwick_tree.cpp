//fenwick trees

#include<bits/stdc++.h>
using namespace std;
class Ftree{
    vector<int> ft;
   public :
   Ftree(int n){
     ft.resize(n);
   }
   
   public :
  void  build(int n,int arr[]){
     for(int i=1;i<n;i++){
        ft[i]+=arr[i];
        if(i+(i&-i) < n){
           ft[i+(i&-i)]+=ft[i];
        }
     }
   }
   
   public :
  void  update(int ind,int val,int n){
     //here val incrementing 
      while(ind < n){
         ft[ind]+=val;
         ind = ind + (ind & -ind);
      }
   }
   
   public:
     int query(int ind){
       int sm = 0;
        while(ind > 0){
          sm+=ft[ind];
          ind = ind-(ind & -ind);
        }
       return sm;
     }
     
   public:
     int rangeSum(int l,int r){
        return query(r)-query(l-1);
     }
};

int main(){
   int n ;
   cin >> n;
   ++n;
   int arr[n];
   for(int i=1;i<n;i++){
       cin >> arr[i];
   }
   Ftree t1 = Ftree(n);
   t1.build(n,arr);
   int q;
   cin >> q;
   while(q--){
      int type ;
      cin >> type;
      if(type==1){
         int l,r;
         cin >> l >> r;
         cout << t1.rangeSum(l,r);
      }
      else{
         int ind , val;
         cin >> ind >> val;
         t1.update(ind,val,n);
      }
   }
}
