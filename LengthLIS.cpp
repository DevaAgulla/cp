class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int> temp;
        for(int i=0;i<arr.size();i++){
            if(temp.size()==0) temp.push_back(arr[i]);
            else if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                temp[ind] = arr[i];
            }
        }
        return temp.size();
    }
};
