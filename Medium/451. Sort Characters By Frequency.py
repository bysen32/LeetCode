# 凑数题
class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        dict = collections.Counter(s)
        return ''.join([x[0] * x[1] for x in sorted(dict.items(), key = lambda x : x[1], reverse=True)])
