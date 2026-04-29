class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i =0;i<(int)nums.size()-2;i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1,k=nums.size()-1;j<k;)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum < 0)
                    j++;
                else if(sum > 0)
                    k--;
                else
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j] == nums[j+1])
                        j++;
                    while(j < k && nums[k] == nums[k-1])
                        k--;
                    j++;
                    k--;
                    
                }
            }
        }
        return res;
    }
};
