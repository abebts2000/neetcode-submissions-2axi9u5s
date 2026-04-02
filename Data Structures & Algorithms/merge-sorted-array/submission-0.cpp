class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int indx = m + n - 1;
        m -= 1;
        n -= 1;
        while(indx>=0)
        {
            if(n < 0 || (m >= 0 && nums1[m] >= nums2[n]))
            {
                nums1[indx] = nums1[m];
                m--;
            }
            else
            {
                nums1[indx] = nums2[n];
                n--;
            }
            indx--;
        }
    }
};