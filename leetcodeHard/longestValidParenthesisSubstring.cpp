int longestValidParentheses(string s) {
        int ans = 0;
        int cnt = 0;
        stack<int>st;
        int n = s.size();
        vector<int> arr(n,-1);
        for(int i=0;i<s.size();i++){
           if(st.empty() or s[i]=='('){
              st.push(i);
           }
           else{
              arr[st.top()] = i;
              st.pop();
           }
        }
         vector<pair<int,int>>vec;
         int i=0;
        while(i<n){
            if(s[i]=='(' and arr[i]!=-1){
                vec.push_back({i,arr[i]});
                i=arr[i]+1;
            }
            else i++;
        }
        i=0;
        int last = -1;
        while(i<vec.size()){
            int start = vec[i].first;
            int end = vec[i].second;
            if(start-1==last or last==-1)cnt+=(end-start+1);
            else{
                cnt = (end-start+1);
            }
            last = end;
            ans =max(ans,cnt);
            i++;
        }
        return max(ans,cnt);
    }
