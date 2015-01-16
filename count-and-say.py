class Solution:
    # @return a string
    def countAndSay(self, n):
        r = '1'
        while n > 1:
            l = list(r)
            l.reverse()
    
            cur_num = None
            cur_count = 0
            cur_r = ""
            while len(l) > 0:
                if cur_num is None:
                    cur_num = l.pop()
                    cur_count += 1
                else:
                    if cur_num == l[-1]:
                        l.pop()
                        cur_count += 1
                    else:
                        cur_r += str(cur_count) + cur_num
                        cur_num = l.pop()
                        cur_count = 1
    
            if cur_count > 0 and cur_num is not None:
                cur_r += str(cur_count) + cur_num
            if cur_r:
                r = cur_r
            n -= 1
    
        return r