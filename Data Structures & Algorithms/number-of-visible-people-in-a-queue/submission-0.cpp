class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>stk;
        vector<int>res(heights.size(),0);
        for(int i = heights.size()-1;i>=0;i--)
        {
            while(!stk.empty() && heights[i] >= stk.top())
            {
                res[i]++;
                stk.pop();
            }
            if(!stk.empty())
                res[i]++;
            stk.push(heights[i]);
        }

        return res;


    }
};