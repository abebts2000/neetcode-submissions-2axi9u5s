class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int c=0;
        int sum =0;
        for(int end =0;end<nums.size();end++)
        {
            sum += nums[end];
            if(counts.find(sum - k) != counts.end())
            {
                c += counts[sum - k];
            }
            counts[sum]++;
        }
        return c;
    }
};