class Solution {
public:
    long long setCnt(long long num,int x){
        vector<long long> vec(64,0);
        for(long long i=63;i>=0;i--){
            if((num&((long long)1<<i))){
                long long pw2 = ((long long)1<<i);
                num-=pw2;
                vec[i] += num+1;
                for(int j=0;j<i;j++)vec[j]+=pw2/2;
            }
        }
        long long cnt = 0;
        for(int i=0;i<=63;i++){
            if((i+1)%x==0) cnt+=vec[i];
        }
        return cnt;
    }
    long long findMaximumNumber(long long k, int x) {
        long long low = 1;
        long long high = 1e15*64;
        long long ans = 0;
        while(low <= high){
            long long mid = (low+high) >> 1;
            if(setCnt(mid,x) <= k){
                low = mid+1;
                ans = mid;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};
