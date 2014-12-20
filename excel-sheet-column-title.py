class Solution:
    # @return a string
    # 我都不知道这是怎么AC的。。。
    def convertToTitle(self, num):
        if num == 0:
            return ''
        elif num % 26 == 0:
            low = 'Z'
        else:
            low = chr(64 + num % 26)
        if num % 26 == 0:
            return self.convertToTitle(num/26-1) +  low
        return self.convertToTitle(num / 26) + low
        