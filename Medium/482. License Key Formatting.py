# 题意：
# 将字符串变成合法序列号
# 规则指定序列号每段长度K, 仅有最左边可以小于K，其他段长度恰好为K
# 如2-4A0r7-4S1 (K=4) => 2-4A0R-74S1
# 解法: 用python字符串切割
class Solution(object):
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        S = S.replace('-', '').upper()
        retStr = S[:len(S)%K]
        for i in range(len(S)%K, len(S), K):
            if(retStr):
                retStr += '-'
            retStr += S[i:i+K]
        return retSt
