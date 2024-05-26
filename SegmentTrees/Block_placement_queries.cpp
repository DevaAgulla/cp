#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//fenwick trees
vector<int> bit;
int n;
void update(int ind,int val){
    while(ind<=n){ //check this
        bit[ind] = max(val,bit[ind]);
        ind +=(ind & -ind);
    }
}

int query(int ind){
    int ans = 0;
    while(ind > 0){
        ans = max(bit[ind],ans);
        ind -= (ind & -ind);
    }
    return ans;
}
    vector<bool> getResults(vector<vector<int>>& queries) {
        //int n = min(5 * 10000, 3 * queries.size())+1;
        n = 5*10000+1;
        set<int> st;
        vector<int> ft(n,0);
        bit = ft;
        st.insert(0),st.insert(n-1);
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==1) st.insert(queries[i][1]);
        }
        for(auto it=st.begin();it!=st.end();it++){
            if(it == st.begin()) continue;
            auto prv = prev(it);
            update(*it,*it-*prv);
        }
        vector<bool> ans;
        for(int i=queries.size()-1;i>=0;i--){
            if(queries[i][0]==1){
                int x = queries[i][1];
                auto it = st.find(x);
                auto prv = prev(it);
                auto nxt = next(it);
                st.erase(it);
                update(*nxt,*nxt-*prv);
            }
            else{
                int r = queries[i][1];
                int sz = queries[i][2];
                auto it = st.upper_bound(r);
                auto prv = prev(it);
                int mx = max(query(*prv),r-*prv);
                ans.push_back(mx >= sz);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
