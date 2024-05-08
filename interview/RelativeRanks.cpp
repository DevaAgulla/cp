class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int m = *max_element(score.begin(),score.end());
        vector<int> linearSort(m+1,-1);
        for(int i=0;i<score.size();i++){
            linearSort[score[i]] = i;
        }
        vector<string>ans(score.size());
        string arr[] = {"Gold Medal","Silver Medal","Bronze Medal"};
        int cnt = 1;
        for(int i=m;i>=0;i--){
            if(linearSort[i]!=-1){
                ans[linearSort[i]] = (cnt<=3)?arr[cnt-1]:to_string(cnt);
               cnt++;
            }   
        }
        return ans;
    }
};
