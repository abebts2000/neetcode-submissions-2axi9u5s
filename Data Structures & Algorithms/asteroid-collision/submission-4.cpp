class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>stk;
        for(auto e:asteroids)
        {
            bool exploded = false;
            while(!stk.empty() && stk.top() > 0 && e < 0)
            {
                if(abs(stk.top()) < abs(e))
                {
                    stk.pop();
                    continue;
                }
                else if(abs(stk.top()) > abs(e))
                {
                    exploded = true;
                    break;
                }
                else
                {
                    stk.pop();
                    exploded = true;
                    break;
                }
            }
            if(!exploded) stk.push(e);
        } 

        vector<int>res;
        while(!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }

        return {res.rbegin(),res.rend()};
    }
};