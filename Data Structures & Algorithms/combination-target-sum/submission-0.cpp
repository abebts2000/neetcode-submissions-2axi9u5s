class Solution {
public:

    void DFS( vector<int>&nums, int i, vector<int>sum,int target, int total, vector<vector<int>>&res)
    {
        if(total > target)
            return;
        if(total == target)
        {
            res.push_back(sum);
            return;
        }
        else
        {
           for(int j =i;j<nums.size();j++)
           {
                total += nums[j];
                sum.push_back(nums[j]);
                DFS(nums,j,sum,target,total,res);
                sum.pop_back();
                total -=nums[j];
           } 
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());

        DFS(nums,0,{},target,0,res);
        return res;
    }
};
