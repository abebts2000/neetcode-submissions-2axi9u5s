# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        visited = set()
        res = []
        def dfs(baseurl,url,indx):
            visited.add(url)
            for nexturl in htmlParser.getUrls(url):
                if nexturl not in visited and nexturl[:indx] == baseurl:
                    dfs(baseurl,nexturl,indx)
        indx = min(len(startUrl),len(startUrl.split('/')[2]))
        baseurl = startUrl[0:indx]
        dfs(baseurl,startUrl,indx)
        return list(visited)

        