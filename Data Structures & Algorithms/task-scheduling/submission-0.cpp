class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) counts[t]++;
        auto cmp = [](pair<char,int>&a, pair<char,int>&b)
        {
            return a.second < b.second;
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(cmp)>pq(cmp);
        for (auto& it : counts) pq.push(it);
        int cycles = 0;
        while (!pq.empty()) {
            vector<pair<char, int>> temp;
            int time = 0;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (auto& item : temp) {
                if (--item.second > 0) pq.push(item);
            }
            cycles += pq.empty() ? time : n + 1;
        }
        return cycles;
    }
};