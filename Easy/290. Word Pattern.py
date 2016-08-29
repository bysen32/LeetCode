class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        rec = {}
        str = str.split(" ")
        if len(str) != len(pattern):
            return False
        for i,s in enumerate(str):
            if rec.has_key(s) and rec[s] != pattern[i]:
                return False
            else:
                rec[s] = pattern[i]
        rec = {}
        for i,s in enumerate(pattern):
            if rec.has_key(s) and rec[s] != str[i]:
                return False
            else:
                rec[s] = str[i]
        return True
