#给定字符串形式如"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
#dir
#	subdir1
#		file1.ext
#		subsubdir1
#	subdir2
#		subsubdir2
#			file2.ext
#转化后形式如上，求最长路径的字符数目
#题解：
#	由分析可得字符\n的数量即为转换后的文件与目录总和，字符\t为文件或目录所处深度
#	增加状态压缩数组dp存储当前深度的前序路径字符数总和
#	读入文件深度更新当前dp值，dp[深度值]+\t的数量即为文件路径字符数
#	
class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        lines = input.split('\n')
        dp = [0 for i in range(len(lines))]
        ret = 0
        for line in lines:
            cnt_t = line.count('\t')
            cnt_l = len(line) - cnt_t
            if cnt_t:
                dp[cnt_t] = dp[cnt_t-1] + cnt_l
            else:
                dp[cnt_t] = cnt_l
            if line.count('.'):
                ret = max(ret, dp[cnt_t] + cnt_t)
        return ret