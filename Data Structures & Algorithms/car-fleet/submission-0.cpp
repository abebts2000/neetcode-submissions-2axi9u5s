class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,double>locTime;
        for(int i =0;i<position.size();i++)
        {
            locTime[position[i]] = (double)(target-position[i])/speed[i];
        }
        std::sort(position.begin(),position.end());
        double time = locTime[position.back()];
        int fleet = 1;
        for(int i = position.size()-2;i>=0;i--)
        {
            if(locTime[position[i]] > time)
            {
                fleet++;
                time = locTime[position[i]];
            }
        }
        return fleet;
    }
};
