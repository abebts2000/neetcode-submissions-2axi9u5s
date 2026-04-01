class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>pq;
        for(auto stone:stones)
        {
            pq.push(stone);
        }
        while(pq.size()>=2)
        {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            if(top1 != top2)
                pq.push(abs(top2-top1));

        }

        return pq.size() ==1?pq.top():0;
    }
};
