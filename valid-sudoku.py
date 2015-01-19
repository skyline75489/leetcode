class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        used = {}
        def refill():
            for i in range(1,10):
                used[i] = False
        def fill_ok(c):
            if c == '.':
                return True
            c = int(c)
            if used[c] == True:
                return False
            used[c] = True
            return True
    
        refill()
        # 每行
        for i in range(0,9):
            row = board[i]
            for j in range(0,9):
                if not fill_ok(row[j]):
                    return False
            refill()

        # 每列
        for i in range(0,9):
            for j in range(0,9):
                if not fill_ok(board[j][i]):
                    return False
            refill()
    
        # 每九个格
        for i in range(0,3):
            for j in range(0,3):
                refill()
                for l in range(i*3, i*3+3):
                    for m in range(j*3, j*3+3):
                        if not fill_ok(board[l][m]):
                            return False
        return True
