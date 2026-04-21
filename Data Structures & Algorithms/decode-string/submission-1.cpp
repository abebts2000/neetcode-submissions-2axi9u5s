class Solution {
public:
    string decodeString(string s) {
       stack<string>stk;
       string temp;
       for(int i =0;i<s.length();)
       {
        if(s[i]=='[')
        {
            stk.push("[");
            i++;
        }
        else if(s[i]==']')
        {
            string content = "";
            while(!stk.empty() && stk.top() != "[") {
                content = stk.top() + content;
                stk.pop();
            }
            stk.pop(); // pop '['
            int num = stoi(stk.top());
            stk.pop();
            string res = "";
            for(int j =0;j<num;j++)
                res += content;
            stk.push(res);
            i++;
        }
        else
        {
            temp = "";
            while(i < s.length() && isalpha(s[i]))
            {
                temp += s[i];
                i++;
            }
            if(temp.length() > 0)
                stk.push(temp);
            
            string numStr = "";
            while(i < s.length() && isdigit(s[i]))
            {
                numStr += s[i];
                i++;
            }
            if(!numStr.empty())
            {
                stk.push(numStr);
            }
        }
       }
       string res = "";
       while(!stk.empty())
       {
        res = stk.top()+res;
        stk.pop();
       }
       return res;
    }
};