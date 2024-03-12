 int divide(int num, int  div) {
        long long ans = 0;
        int sign= 0;
        if(num==INT_MIN and div==-1) return INT_MAX;
        if(div<0 and num > 0) sign = 1;
        if(div>0 and num < 0) sign = 1;
      long long  div2 =  abs((long long)div);
       long long num2 =  abs((long long)num);
        while(num2 >= div2){
            int cnt = 0;
            while((div2<<(cnt+1)) <= num2){
                cnt++;
            }
            ans+=(1 << cnt);
            num2-=(div2 << cnt);
        }
        if(sign) ans = -1*ans;        
        return ans;
    }
