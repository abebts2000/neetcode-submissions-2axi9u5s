class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>stk;
        int area = 0;
        heights.push_back(0);
        for(int i =0;i<heights.size();i++)
        {
            int start = i;
            while(!stk.empty() && stk.top().first>heights[i])
            {
                auto top = stk.top();
                area = max(area,(i-top.second)*top.first);
                start = top.second;
                stk.pop();
            }
            stk.push({heights[i],start});
        }
        return area;
    }
};
