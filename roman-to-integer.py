class Solution:
    # @return an integer
    def romanToInt(self, s):
        romanIntMap = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        allowFollow = {
            'I':set(['V', 'X']),
            'X':set(['L', 'C']),
            'C':set(['D', 'M'])
        }
    
        l = list(s)
        index = 0
        result = 0
        while True:
            try:
                cur_char = l[index]
            except IndexError:
                break
            num = romanIntMap[cur_char]
            try:
                next_char = l[index+1]
                if cur_char in allowFollow.keys() and next_char in allowFollow[cur_char]:
                    num = romanIntMap[next_char] - romanIntMap[cur_char]
                    index += 1
    
            except IndexError, KeyError:
                pass
            
            result += num
            index += 1
        return result
