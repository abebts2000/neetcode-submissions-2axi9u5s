class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        res = set()
        for email in emails:
            name,domain = email.split('@')
            name2 =""
            for i in range(len(name)):
                if name[i] == '+':
                    break
                elif name[i] == '.':
                    continue
                else:
                    name2+=name[i]
            res.add(name2+'@'+domain)
        return len(res)
