class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        m = len(matrix)
        n = len(matrix[0])
        for row in range(0, m):
            for col in range(0, n):
                if matrix[row][col] == 0:
                    matrix[row][col] = '.'
    
        for row in range(0, m):
            for col in range(0, n):
                if matrix[row][col] == '.':
                    matrix[row][col] = 0
                    self.clearRowAndCol(matrix, row, col)
    
    
    def clearRowAndCol(self, matrix, row, col):
        m = len(matrix)
        n = len(matrix[0])
        for r in range(0, m):
            matrix[r][col] = 0 if matrix[r][col] != '.' else '.'
    
        for c in range(0, n):
            matrix[row][c] = 0 if matrix[row][c] != '.' else '.'
    
            