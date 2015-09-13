class Solution(object):
    def isAnagram(self, s, t):
        # 直接用自带的 Counter 模块了，不用的话思路也是一样的
        # 就是比较两个字符串中各个字母的个数
        from collections import Counter
        r1 = Counter(s)
        r2 = Counter(t)
        return r1 == r2
