class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int  left_small[n], right_small[n];
        
        for(int i=0; i<n; ++i){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                left_small[i] = 0;
            }
            else{
                left_small[i] = st.top() + 1;
            }
            st.push(i);
        }
        //empty the stack
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                right_small[i] = n-1;
            }
            else{
                right_small[i] = st.top()-1;
            }
            st.push(i);
        }
        int Max = 0;
        for(int i=0; i<n; ++i){
            Max = max(Max, (right_small[i] - left_small[i] + 1) * heights[i]);
        }
        return Max;
    }
};