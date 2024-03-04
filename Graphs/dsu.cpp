#include<bits/stdc++.h>
class dsu{
   public : vector<int>par,rank,size;
   public:
   dsu(int n){
     par.resize(n+1);
     rank.resize(n+1);
     size.resize(n+1);
     for(int i=0;i<=n;i++){
       par[i] = i;
       size[i] = 1;
       rank[i] = 0;
     }
   }
   
   int findPar(int node){
     if(par[node]==node) return node;
     return par[node] = findPar(par[node]);
   }
   
   void unionByRank(int u,int v){
      int pu = findPar(u);
      int pv = findPar(v);
      if(pu==pv) return;
      if(rank[pv] < rank[pu]) par[pv] = pu;
      else if(rank[pu] < rank[pv]) par[pu] = pv;
      else{
         par[pu] = pv;
         rank[pv]++;
      } 
   }
   void unionBySize(int u,int v){
      int pu = findPar(u);
      int pv = findPar(v);
      if(pu==pv) return;
      if(size[pv] < size[pu]){
         par[pv] = pu;
         size[pu]+=size[pv];
      }
      else{
        par[pu] = pv;
        size[pv]+=size[pu];
      }  
   }
   
};
