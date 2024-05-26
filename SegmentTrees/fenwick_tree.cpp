//fenwick trees

#include<bits/stdc++.h>
using namespace std;
vector<int> bit;
int n;
void update(int ind,val){
    while(ind<=n){ //check this
        bit[ind]+=val;
        ind +=(ind & -ind);
    }
}

int query(int ind){
    int ans = 0;
    while(ind > 0){
        ans+=bit[ind];
        ind -= (ind & -ind);
    }
    return ans;
}
