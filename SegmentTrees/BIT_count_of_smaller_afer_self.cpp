
class Solution {
public:
vector<int> bit;
int n;
void update(int ind,int val){
    while(ind<=n){
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
    vector<int> countSmaller(vector<int>& nums) {
         n =nums.size();
        bit.resize(n+1);
       vector<pair<int,int>>vec;
       for(int i=0;i<nums.size();i++)vec.push_back({nums[i],i});
       sort(vec.begin(),vec.end());
       vector<int> ans(n);
       for(int i=0;i<n;i++){
        int ele = vec[i].first;
        int ind = vec[i].second;
        update(ind+1,1);
        int s = query(n) - query(ind+1);
        ans[ind] = s;
       }
       return ans;
    }
};
