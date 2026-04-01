class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>mp = {{'}','{'},{']','['},{')','('}};
        stack<char>stk;
        for(auto e:s)
        {
            if(e == '[' || e == '{' || e =='(')
            stk.push(e);
            else
            {
                if(stk.empty() || stk.top() != mp[e])
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
