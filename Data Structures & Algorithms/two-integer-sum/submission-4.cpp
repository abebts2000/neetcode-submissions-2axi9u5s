class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>>mp;
        for(int i =0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);

        }
        
        for(int i =0;;i++)
        {
            int num2 = target - nums[i];
            if(mp.find(num2) != mp.end() )
            {
                if(num2 == nums[i] && mp[num2].size() > 1)
                    return {i,mp[num2][1]};
                else if(num2 != nums[i])
                    return {i, mp[num2][0]};
            }
        }
        return {};

    }
};
