class Solution:
    # @return a boolean
    def isValid(self, s):
        parenthe_map = {'(': ')',
                        '{': '}',
                        '[': ']'
                        }
        l = list(s)
        l.reverse()
        stack = []
        while len(l) > 0:
            top = l.pop()
            if len(stack) == 0:
                stack.append(top)
                continue
            try:
                # Match
                if parenthe_map[stack[-1]] == top:
                    stack.pop()
                else:
                    stack.append(top)
            except KeyError:
                stack.append(top)
            
        return len(stack) == 0