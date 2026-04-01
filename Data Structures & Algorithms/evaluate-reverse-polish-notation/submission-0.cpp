class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>stk;
        for(auto e:tokens)
        {
            if(!stk.empty() && (e == "+"|| e == "-" || e == "*" || e == "/") )
            {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                if ( e== "+")
                {
                    int res = num1 + num2;
                    stk.push(res);
                }
                else if ( e== "-")
                {
                    int res = num1 - num2;
                    stk.push(res);
                }
                else if ( e== "*")
                {
                    int res = num1 * num2;
                    stk.push(res);
                }
                else 
                {
                    int res = num1 / num2;
                    stk.push(res);
                }
            }
            else
            {
                stk.push(stoi(e));
            }
        }
        return stk.top();
    }
};
