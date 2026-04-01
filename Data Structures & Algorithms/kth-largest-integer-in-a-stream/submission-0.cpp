class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (int x : nums) add(x);
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k_)
            pq.pop();
        return pq.top();
    }
    int k_;
    priority_queue<int,vector<int>,greater<int>> pq;
};
