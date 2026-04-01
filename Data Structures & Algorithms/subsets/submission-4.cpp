class Solution {
public:

    void DFS(vector<int>&nums,int indx, vector<int>sofar, vector<vector<int>>&res)
    {
        res.push_back(sofar);
        for(int i = indx+1;i<nums.size();i++)
        {
            sofar.push_back(nums[i]);
            DFS(nums,i,sofar,res);
            sofar.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        DFS(nums,-1,{},res);
        return res;
        
    }
};
