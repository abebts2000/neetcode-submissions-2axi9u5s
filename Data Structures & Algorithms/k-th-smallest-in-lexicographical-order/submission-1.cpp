class Solution {
public:

    struct TrieNode
    {
        map<int,TrieNode*>childs;
        int count = 0;
    };

    struct Trie
    {
        TrieNode*root = new TrieNode();
        void add(int num)
        {
            string s = to_string(num);
            auto temp = root;
            for(char c : s) {
                int digit = c - '0';
                if(temp->childs.find(digit) == temp->childs.end())
                {
                    temp->childs[digit] = new TrieNode();
                }
                temp = temp->childs[digit];
                temp->count++;
            }
        }

        long long getSteps(long long curr, long long n) {
            long long steps = 0;
            long long first = curr;
            long long last = curr;
            while (first <= n) {
                steps += min((long long)n + 1, last + 1) - first;
                first *= 10;
                last = last * 10 + 9;
            }
            return steps;
        }

        int findKthSmallest(int n, int k) {
            long long curr = 1;
            k--;
            while (k > 0) {
                long long steps = getSteps(curr, n);
                if (steps <= k) {
                    curr++;
                    k -= steps;
                } else {
                    curr *= 10;
                    k--;
                }
            }
            return curr;
        }
    };

    int findKthNumber(int n, int k) {
       Trie trie;
       return trie.findKthSmallest(n, k);
    }
};