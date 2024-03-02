class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int area = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i==n or arr[st.top()] > arr[i])){ 
                int h = arr[st.top()];
                st.pop();
                int w = 0;
                if(st.empty()) w = i;
                else w = i-st.top()-1;
                area = max(area,w*h);
            }
            st.push(i);
        }
        return area;
    }
};
