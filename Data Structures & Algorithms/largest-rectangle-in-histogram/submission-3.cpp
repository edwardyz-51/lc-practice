class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        heights.push_back(0);
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i){
            while (!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()]; st.pop();
                int left = st.empty() ? 0 : st.top()+1;
                int right = i;
                int width = right - left;
                ans = max (ans, width *h);
                
            }
            st.push(i);
        }
        return ans;

    }
};
