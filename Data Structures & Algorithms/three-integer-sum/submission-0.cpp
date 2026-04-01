class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i =0;i<(int)nums.size()-2;)
        {
            for(int j=i+1,k=nums.size()-1;j<k;)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum < 0)
                {
                    j++;
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                }
                else if(sum > 0)
                {
                    k--;
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }
                else
                {
                    res.push_back({nums[i],nums[j],nums[k]});
                     j++;
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                     k--;
                    while(j < k && nums[k] == nums[k+1])
                        k--;
                }
            }
            i++;
            while(i < (int)nums.size()-2 && nums[i] == nums[i-1])
                i++;
        }
        return res;
    }
};
