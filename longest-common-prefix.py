class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if len(strs) == 0:
            return ''
        first = strs[0]
        for i in range(0, len(first)):
            for s in strs[1:]:
                try:
                    if s[i] != first[i]:
                        return first[0:i]
                except IndexError:
                    return first[0:i]
    
        return first
