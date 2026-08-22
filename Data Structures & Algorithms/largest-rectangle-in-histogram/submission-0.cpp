class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;              // stores indices
        heights.push_back(0);       // sentinel to clear stack
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();

                int right = i;
                int left = st.empty() ? 0 : st.top() + 1;
                int width = right - left;

                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
