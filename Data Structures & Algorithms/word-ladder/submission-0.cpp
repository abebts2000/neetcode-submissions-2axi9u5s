class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(),wordList.end());
        queue<pair<pair<string,int>,unordered_set<string>>>q;

        q.push({{beginWord,1},{beginWord}});
        while(!q.empty())
        {
            auto [curWord,depth] = q.front().first;
            auto st = q.front().second;
            q.pop();

            if(curWord == endWord)
                return depth;
            string orig = curWord;
            for(int i =0;i<curWord.length();i++)
            {
                curWord = orig;
                for(int j =0;j<26;j++)
                {
                    curWord[i] = 'a'+j;
                    if(words.find(curWord) != words.end() && st.find(curWord) == st.end() && curWord != orig)
                    {
                        st.insert(curWord);
                        q.push({{curWord,depth+1},st});
                        st.erase(curWord);
                    }
                }
            }

        }
        return 0;

    }
};
