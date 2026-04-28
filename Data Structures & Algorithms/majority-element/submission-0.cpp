class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res =0,count =0;
        for(auto e:nums)
        {
            if(count == 0)
                res = e;
            count += (e ==res)?1:-1;
        }
        return res;
    }
};