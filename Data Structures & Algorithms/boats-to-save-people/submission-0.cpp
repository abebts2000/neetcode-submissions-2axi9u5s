class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int l=0,r=people.size()-1;
        int c =0;
        while(l<=r)
        {
            if(l==r)
            {
                c++;
                break;
            }
            int sum = people[l]+people[r];
            if(sum <= limit)
            {
                c++;
                l++,r--;
            }
            else
            {
                r--;
                c++;
            }
        }
        return c;
    }
};