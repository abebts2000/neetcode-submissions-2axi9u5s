class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int c =0;
        int sum =0;
        for(int i =0;i<arr.size();i++)
        {
            sum += arr[i];
            if(i>=(k-1))
            {
                if(sum >= k*threshold)
                    c++;
                sum -= arr[i+1-k];
            }
        }
        return c;
    }
};