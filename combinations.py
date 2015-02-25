class Solution:
    # @return a list of lists of integers
    def combine(self, n, k):
        r = []
        l = [i for i in range(0, k)]
        if n > 0:
            self.dfs2(r, l, 0, k, 1 ,n)
        return r

    def dfs2(self, result, cur_arr, cur_depth, max_depth, start, end):
        if cur_depth == max_depth:
            print(cur_arr)
            result.append(list(cur_arr))
        else:
            for i in range(start, end+1):
                cur_arr[cur_depth] = i
                self.dfs2(result, cur_arr, cur_depth+1, max_depth, i+1, end)
