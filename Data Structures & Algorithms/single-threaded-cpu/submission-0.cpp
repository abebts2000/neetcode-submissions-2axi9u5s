class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
      //vector<pair<int,pair<int,int>>>dc;
      for(int i=0;i<tasks.size();i++)
      {
        tasks[i].push_back(i);
      }  
      sort(tasks.begin(),tasks.end());
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>hp;
      int i =0;
      int time = tasks[0][0];
      vector<int>res;
      while(!hp.empty() || i < tasks.size())
      {
        while(i< tasks.size() && time >= tasks[i][0])
        {
            hp.push({tasks[i][1],tasks[i][2]});
            i++;
        }
        if(hp.empty())
        {
            time = tasks[i][0];
        }
        else
        {
            auto [proctime,indx] = hp.top();
            hp.pop();
            time += proctime;
            res.push_back(indx);
        }
      }
      return res;
    }
};