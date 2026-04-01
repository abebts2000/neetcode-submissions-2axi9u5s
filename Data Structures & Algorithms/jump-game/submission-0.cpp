class Solution {
public:
    bool DFS(vector<int>& nums, int indx, vector<int>& memo)
    {
        if(indx >= nums.size())
            return false;
        if(indx==nums.size()-1)
            return true;
        if(memo[indx] != -1)
            return memo[indx];

        int mx = std::min((int)nums.size() - 1, indx+nums[indx]);

        for(int nxt = mx; nxt > indx; nxt--)
        {
            if(DFS(nums, nxt, memo))
                return (memo[indx] = 1);
        }
        return (memo[indx] = 0);

    }
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return DFS(nums, 0, memo);
    }
};