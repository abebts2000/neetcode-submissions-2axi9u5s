class Solution {
public:
    int find(int x, unordered_map<int,int>&parent)
    {
        if(x != parent[x])
        {
            parent[x] = find(parent[x],parent);
        }
        return parent[x];
    }

    bool union2(int x, int y, unordered_map<int,int>&parent, unordered_map<int,int>&rank)
    {
        int px = find(x,parent);
        int py = find(y,parent);
        if(px==py)
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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,int>parent;
        unordered_map<int,int>rank;
        for(auto e:edges)
        {
            parent[e[0]] = e[0];
            parent[e[1]] = e[1];
            rank[e[0]] = rank[e[1]] = 1;
        }
        
        for(auto e:edges)
        {
            int px = find(e[0],parent);
            int py = find(e[1],parent);

            if(!union2(e[0],e[1],parent,rank))
                return {e[0],e[1]};

        }
        

    }
};
