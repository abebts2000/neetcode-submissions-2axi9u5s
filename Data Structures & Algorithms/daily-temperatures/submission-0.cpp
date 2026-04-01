class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>stk;
        vector<int>ans(temperatures.size(),0);
        for(int i = temperatures.size()-1;i>=0;i--)
        {
            //if top  > cur ... ans[i] = 1 but add it to top
            //if top  <= cur ..pop till you get top > cur || empty

            while(!stk.empty() && stk.top().first <= temperatures[i])
            {
                stk.pop();
            }
            if(stk.empty())
                ans[i] =0;
            else
            {
                ans[i]= stk.top().second - i;
            }
            stk.push(make_pair(temperatures[i],i));

        }
        return ans;
        
    }
};
