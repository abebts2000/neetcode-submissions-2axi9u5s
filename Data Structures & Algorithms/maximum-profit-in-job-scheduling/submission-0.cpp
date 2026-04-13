class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        for(int i =0;i<startTime.size();i++)
        {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        std::sort(jobs.begin(),jobs.end(),[](const vector<int>&a, const vector<int>&b)
        {
            if(a[0] == b[0])
                return a[1] <= b[1];
            return a[0] <= b[0];
        });
        vector<int>dp(startTime.size(),0);
        int mx =0;
        for(int i =0;i< startTime.size();i++)
        {
            dp[i] = jobs[i][2];
            for(int j=0;j<i;j++)
            {
                if(jobs[j][1] <= jobs[i][0])
                {
                    dp[i] = max(dp[i],jobs[i][2]+dp[j]);
                }
            }
            mx= max(mx,dp[i]);
        }
        for(auto e:dp)
            cout<<e<<",";
        return mx;


    }
};