class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = matrix[0].size();
      int l=0,h=m-1;
      int r = 0;

      while(l<=h)
      {
        int mid = l+(h-l)/2;
        if(target < matrix[mid][0])
            h = mid-1;
        else if(target > matrix[mid][n-1])
            l = mid+1;
        else {
            r = mid;
            l = 0; h = 0; // trigger the flag to enter next block
            break;
        }
      }  

      if(l<=h)
      {
        l = 0, h = n - 1;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(target < matrix[r][mid])
                h = mid-1;
            else if(target > matrix[r][mid])
                l = mid+1;
            else
                return true;
        }
      }
      return false;

    }
};
