class Solution:

# int minCost(vector<int>& cost, vector<int>&cache, int indx)
#     {
#         if(indx == cost.size())
#             return 0;
#         if(cache[indx] == -1)
#         {
#             cache[indx] = cost[indx]+min(minCost(cost,cache,indx+1), minCost(cost,cache,indx+2));
#         }
#         return cache[indx];
#     }
#     int minCostClimbingStairs(vector<int>& cost) {
#         vector<int>cache(cost.size(),-1);
#         return min(minCost(cost,cache,0),minCost(cost,cache,1));
#     }
    
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        def minCost(cost: List[int],cache: List[int], indx: int) ->int:
            if indx >= len(cost):
                return 0
            if cache[indx] == -1:
                cache[indx] = cost[indx]+ min(minCost(cost,cache,indx+1),minCost(cost,cache,indx+2))
            return cache[indx]
        cache = [-1]*len(cost)
        return min(minCost(cost,cache,0),minCost(cost,cache,1))