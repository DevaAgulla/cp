class Solution {
public:
     int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int area = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i==n or arr[st.top()] >= arr[i])){ 
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> arr(m);
        int area =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') arr[j]++;
                else arr[j] = 0;
            }
            area = max(area,largestRectangleArea(arr));
        }
        return area;
    }
};
