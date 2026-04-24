class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string>stk;
        for(auto e:operations)
        {
            if(e == "+")
            {
                int top1 = stoi(stk.top());
                stk.pop();
                int top2 = stoi(stk.top());
                stk.push(to_string(top1));
                stk.push(to_string(top1+top2));
            }
            else if(e == "D")
            {
                int top = stoi(stk.top());
                stk.push(to_string(2*top));
            }
            else if(e == "C")
            {
                stk.pop();
            }
            else
                stk.push(e);
        }
        int res = 0;
        while(!stk.empty())
        {
            res += stoi(stk.top());
            stk.pop();
        }
        return res;
    }
};