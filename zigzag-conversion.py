class Solution:
    # @return a string
    def convert(self, s, nRows):
        row = nRows
        between = nRows - 2
        result = []
        for i in range(row):
            result.append([])
        l = list(s)
        l.reverse()
        while len(l) > 0:
            try:
                for i in range(row):
                    result[i].append(l.pop())
    
                for i in reversed(range(1, row-1)):
                    result[i].append(l.pop())
            except IndexError:
                break
    
        result_str = ""
        for r in result:
            result_str += "".join(r)
    
        return result_str