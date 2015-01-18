class Solution:
    # @param s, a string
    # @return an integer
    # 这个比title那个题简单
    def titleToNumber(self, s):
        result = 0
        l = list(s)
        l.reverse()
        for k, v in enumerate(l):
            result += (ord(v) - 64) *  pow(26, k)
        return result
