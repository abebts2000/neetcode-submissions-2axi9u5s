/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:

    void DFS(string baseUrl, HtmlParser htmlParser, string url, unordered_set<string>&visited, vector<string>&res, int indx)
    {
        visited.insert(url);
        for(auto e:htmlParser.getUrls(url))
        {
            
            if(visited.find(e) == visited.end() && e.substr(0,indx) == baseUrl)
            {
                 DFS(baseUrl,htmlParser,e,visited,res,indx);
            }
        }
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        int indx = min(startUrl.length(),startUrl.find('/', 7));
        string baseurl = startUrl.substr(0,indx);
        unordered_set<string>visited;
        vector<string>res;
        std::cout<<baseurl<<endl;
        DFS(baseurl,htmlParser,startUrl,visited,res,indx);
        return vector<string>(visited.begin(), visited.end());
    }
};
