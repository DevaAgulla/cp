vector <int> search(string pattern, string text)
        {
            vector<int> res;
            int h = 1;
            int p = 0;
            int t = 0;
            int d = 256;
            int mod = INT_MAX;
            int m = pattern.size();
            int n = text.size();
            if(n < m) return res;
            for(int i=0;i<m-1;i++){
                h = (h*d)%mod;
            }
            for(int i=0;i<m;i++){
                p = (p*d + pattern[i])%mod;
                t = (t*d + text[i])%mod;
            }
            
            for(int i=0;i<=n-m;i++){
                if(p==t){
                    int f = 1;
                    for(int j=0;j<m;j++){
                        if(pattern[j]!=text[i+j]) f= 0;
                    }
                    if(f) res.push_back(i+1);
                }
                t = (d*(t-h*text[i]) + text[i+m])%mod;
            }
            return res;
        }
