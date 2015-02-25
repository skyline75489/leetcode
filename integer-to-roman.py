class Solution:
    # @return a string
    def intToRoman(self, num):
        """简单粗暴的做法，其实很容易用循环优化一下，让代码变得更简洁
        """
        result = ""
        n = num
        i = n / 1000
        if i > 0:
            result += 'M' * i
            n -= i * 1000
    
        j = n / 100
        if j <= 3:
            result += 'C' * j
        if j == 4:
            result += 'CD'
        if j >= 5 and j < 9:
            result += 'D' + (j-5) * 'C'
        if j == 9:
            result += 'CM'
        n -= j * 100
    
        j = n / 10
        if j <= 3:
            result += 'X' * j
        if j == 4:
            result += 'XL'
        if j >= 5 and j < 9:
            result += 'L' + (j-5) * 'X'
        if j == 9:
            result += 'XC'
        n -= j * 10
    
        j = n
        if j <= 3:
            result += 'I' * j
        if j == 4:
            result += 'IV'
        if j >= 5 and j < 9:
            result += 'V' + (j-5) * 'I'
        if j == 9:
            result += 'IX'
    
        return result