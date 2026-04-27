class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0LL) <
            accumulate(cost.begin(), cost.end(), 0LL)) {
            return -1;
        }
        int fuel =0,start =0;
        for(int i =0;i<gas.size();i++)
        {
            fuel += gas[i]-cost[i];
            if(fuel < 0)
            {
                start = i+1;
                fuel =0;
            }
                
        }
        return start;


    }
};
