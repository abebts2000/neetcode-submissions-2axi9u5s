class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0)
            return false;
        
        sort(hand.begin(),hand.end());
        unordered_set<int>st;
        int numgrps = hand.size()/groupSize;
        while(numgrps > 0)
        {
            numgrps--;
            int c =0;
            int start =0;
            while(start < hand.size() && st.find(start) != st.end() )
                start++;
            
            int prev_idx = start;
            st.insert(start);
            int next = start+1;
            c=1;
            for(;next<hand.size();next++)
            {
                if(c==groupSize)
                    break;
                if(st.find(next) == st.end())
                {
                    if(hand[next] == hand[prev_idx])
                        continue;
                    if(hand[next] != hand[prev_idx]+1)
                        return false;
                    st.insert(next);
                    c++;
                    prev_idx = next;
                }
            }

            if(c != groupSize)
                return false;
            
        }
        return true;
    }
};
