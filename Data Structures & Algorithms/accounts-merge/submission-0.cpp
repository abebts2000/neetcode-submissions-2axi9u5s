class UnionFind{
    vector<int>parent;
    vector<int>rank;
public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n,1);
        for(int i =0;i<n;i++)
            parent[i] =i;
    }

    int find(int x)
    {
        if(x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unionSets(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if(px == py)
            return false;
        if(rank[px] > rank[py])
        {
            parent[py] = px;
            rank[px] += rank[py];
        }
        else
        {
            parent[px] = py;
            rank[py] += rank[px];
        }
        return true;
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string,int>emailToAccId;
        for(int i =0;i<n;i++)
            for(int j = 1;j<accounts[i].size();j++)
            {
                string email = accounts[i][j];
                if(emailToAccId.find(email) != emailToAccId.end())
                    uf.unionSets(i,emailToAccId[email]);
                else
                    emailToAccId[email] = i;
            }  
        std::map<int,vector<string>>emailGroup;
        for(auto&[email, acctId]:emailToAccId)
        {
            int leader = uf.find(acctId);
            emailGroup[leader].push_back(email);
        }

        vector<vector<string>>res;
        for(auto& [accId,emails]:emailGroup)
        {
            std::sort(emails.begin(),emails.end());
            vector<string>merged;
            merged.push_back(accounts[accId][0]);
            merged.insert(merged.end(),emails.begin(), emails.end());
            res.push_back(merged);

        }
        return res;
    }
};