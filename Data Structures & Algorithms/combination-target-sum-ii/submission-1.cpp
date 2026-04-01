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
                if(j> i && nums[j] == nums[j-1])
                    continue;
                sum.push_back(nums[j]);
                DFS(nums,j+1,sum,target,total + nums[j],res);
                sum.pop_back();
           } 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());

        DFS(candidates,0,{},target,0,res);
        return res;
    }
};
