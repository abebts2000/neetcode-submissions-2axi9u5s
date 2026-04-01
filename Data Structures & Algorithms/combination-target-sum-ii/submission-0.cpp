class Solution {
public:

    void DFS( vector<int>&nums, int i, vector<int>sum,int target, int total, set<vector<int>>&res)
    {
        if(total > target)
            return;
        if(total == target)
        {
            res.insert(sum);
            return;
        }
        else
        {
           for(int j =i+1;j<nums.size();j++)
           {
                total += nums[j];
                sum.push_back(nums[j]);
                DFS(nums,j,sum,target,total,res);
                sum.pop_back();
                total -=nums[j];
           } 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>res;
        sort(candidates.begin(),candidates.end());

        DFS(candidates,-1,{},target,0,res);
        return vector<vector<int>>{res.begin(),res.end()};
    }
};
