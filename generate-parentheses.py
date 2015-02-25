class Solution:
    # @param an integer
    # @return a list of string
    def generateParenthesis(self, n):
        result = set()
        if n > 0:
            self.dfs(result, "", n, n)
        return list(result)


    def dfs(self, result_set, cur_string, left, right):
        if left == 0 and right == 0:
            result_set.add(cur_string)
        else:
            if left > 0:
                self.dfs(result_set, cur_string + '(', left-1, right)
            if left < right and right > 0:
                self.dfs(result_set, cur_string + ')', left, right-1)
