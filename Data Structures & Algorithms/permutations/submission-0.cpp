class Solution {
public:

    void DFS(vector<int> nums, int i, vector<vector<int>>&res, vector<int>sofar)
    {
        if(i==nums.size()) {
            res.push_back(sofar);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            sofar.push_back(nums[i]);
            DFS(nums,i+1,res,sofar);
            sofar.pop_back();
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        DFS(nums,0,res,{});
        return res;
    }
};
