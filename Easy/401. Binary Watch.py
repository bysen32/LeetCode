# 题目大意: 使用二进制表示的时钟，问提供n位二进制能组成的时间表
# 思路：反转枚举时间 计算是否与需求二进制相符
class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        ret = []
        for h in range(0, 12):
            for m in range(0, 60):
                if num == bin(h).count('1')+bin(m).count('1'):
                    ret.append("%d:%02d" % (h, m))
        return ret
