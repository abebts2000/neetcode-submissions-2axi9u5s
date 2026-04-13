class Solution {
public:
    struct keyhash
    {
        size_t operator()(const vector<int>&other) const
        {
            size_t h1 = std::hash<int>{}(other[0]);
            size_t h2 = std::hash<int>{}(other[1]);
            size_t h3 = std::hash<int>{}(other[2]);
            size_t h4 = std::hash<int>{}(other[3]);
            return h1^(h2 << 1) ^ (h3 << 2)^ (h3 << 3);
        }
    };

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int n=nums.size();
        unordered_set<vector<int>,keyhash>res;
        for(int i =0;i<n-3;i++)
        {
            for(int j = i+1;j<n-2;j++)
            {
                for(int k=j+1,l=n-1;k<l;)
                {
                    long long sum = (long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum == target)
                    {
                        res.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++,l--;
                    }
                    else if(sum > target)
                        l--;
                    else
                        k++;
                }
            }
        }
        return vector<vector<int>>{res.begin(),res.end()};
    }
};