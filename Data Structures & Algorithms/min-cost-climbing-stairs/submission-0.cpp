class Solution {
public:
    int minCost(vector<int>& cost, vector<int>&cache, int indx)
    {
        if(indx == cost.size())
            return 0;
        if(cache[indx] == -1)
        {
            cache[indx] = cost[indx]+min(minCost(cost,cache,indx+1), minCost(cost,cache,indx+2));
        }
        return cache[indx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>cache(cost.size(),-1);
        return min(minCost(cost,cache,0),minCost(cost,cache,1));
    }
};
