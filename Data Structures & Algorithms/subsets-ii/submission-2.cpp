class Solution {
public:

    void DFS(int indx, vector<int>subset,vector<int>& nums, vector<vector<int>>& res)
    {
        res.push_back(subset);
        for(int j = indx;j<nums.size();j++)
        {
            if(j>indx && nums[j] == nums[j-1])
                continue;
            subset.push_back(nums[j]);
            DFS(j+1,subset,nums,res);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        DFS(0,{},nums,res);
        return res;
    }
};
