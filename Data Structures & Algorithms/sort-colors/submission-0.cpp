class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>v(3,0);
        for(auto e:nums)
           v[e]++;
        int i=0;
        for(int j=0;j<3;j++)
        {
            int c = v[j];
            while(c>0)
            {
                nums[i]=j;
                i++;
                c--;
            }
        }

    }
};