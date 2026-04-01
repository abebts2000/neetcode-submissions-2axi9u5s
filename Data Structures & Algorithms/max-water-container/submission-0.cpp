class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mxarea =0;
        for(int i =0,j=heights.size()-1;i<j;)
        {
            int area = min(heights[i],heights[j])*(j-i);
            mxarea = max(mxarea,area);
            if(heights[i] < heights[j])
                i++;
            else if(heights[i] > heights[j])
                j--;
            else
                i++,j--;
        }
        return mxarea;
    }
};
