vector<int> kmp(string str){
    int n = str.size();
    vector<int>lps(n,0);
    for(int i=1;i<n;i++){
        int pre = lps[i-1];
        while(pre>0 and str[i]!=str[pre]){
            pre = lps[pre-1];
        }
        lps[i] = pre+(str[i]==str[pre]);
    }
    return lps;
}
class Solution {
public:
    string shortestPalindrome(string s) {
        string dummystr = s;
        reverse(dummystr.begin(),dummystr.end());
        string temp = s+"#"+dummystr;
        vector<int> lps = kmp(temp);
        int len = lps[lps.size()-1];
        string addstr = "";
        for(int i=s.size()-1;i>=len;i--)addstr+=s[i];
        return addstr+s;
    }
};
